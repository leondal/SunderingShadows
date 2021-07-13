//_rage.c
//Updated by ~Circe~ 5/14/13 to match current code and standards
//Backup is _rage.circe
#include <spell.h>
#include <daemons.h>
#include <magic.h>
#include <std.h>

inherit SPELL;

int mybonus;

void create() {
    ::create();
    set_spell_name("rage");
    set_spell_level(([ "bard" : 2, "mage": 3, "oracle" : 3, "magus" : 3, "cleric" : 3 ]));
    set_mystery("lunar");
    set_bonus_type("morale");
    set_domains(({ "destruction", "strength" }));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS rage");
    set_description("%^RESET%^This spell allows the caster to enter a fit of furious rage, making them deadly in combat for the duration. The ability will last longer, and grow stronger, as the caster gains levels.

%^RED%^%^BOLD%^N.B.%^RESET%^ Being enraged means that you are maddened uncontrollably. This is *not* a state in which you can calmly participate in a normal conversation, undertake delicate tasks, cast offensive spells, solve problems, or pretty much do anything other than shout obscenities and kill things. This spell won't work in conjunction with similar magical effects, such as rally, transformation, rage, berserker and fell flight.

%^RED%^%^BOLD%^See also:%^RESET%^ rage *feats");
    set_components(([
                        "mage" : ([ "mini shovel" : 1 ]),
    ]));
    set_verbal_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
	tell_object(caster,"%^RED%^A red haze clouds your vision as you feel a rage"+
		" moving through your body.");
	tell_room(place,"%^RED%^"+caster->QCN+" rolls "+caster->QP+" eyes back"+
		" and begins to shake with rage.",caster);
	return "display";
}

int preSpell(){
    if ((int)CASTER->query_property("raged") || (int)CASTER->query_property("transformed") || (int)caster->query_property("dance-of-cuts")) {
        tell_object(caster,"Similar magic already affects you.");
        return 0;
    }
    // this gives extra attacks so should not stack with haste/fell flight. Already does not activate if rally is up so that needs blocked too.
    if ((int)CASTER->query_property("hasted") || pointerp(CASTER->query_property("rally"))) {
        tell_object(caster,"Similar magic already affects you.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {

    tell_room(place,"%^BOLD%^%^RED%^The essence of battle and the rage of war falls upon "+caster->QCN+".",caster);
    tell_object(caster, "%^BOLD%^%^RED%^The essence of battle and the rage of war falls upon you.");

    mybonus = clevel/8;
    caster->add_attack_bonus(mybonus);
    caster->add_damage_bonus(mybonus);
    caster->set_property("raged",1);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("rage",ROUND_LENGTH);
    caster->set_property("spelled", ({TO}) );

}

void rage(){
    if (!objectp(caster)) return;
    if(sizeof(caster->query_attackers())){
        if(!random(4)){
           tell_object(caster,"%^BOLD%^%^RED%^You feel rage burning your veins.");
           tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+"'s eyes flash with rage.",caster);
        }
        caster->execute_attack();
        if(sizeof(caster->query_classes()) == 1){
           caster->execute_attack();
        }
    }

    if ((!caster->is_in_combat()) && (!random(10))){
        //caster->do_damage("torso",random(2)+1);
        damage_targ(caster, "torso", roll_dice(1, 2), "untyped");
        tell_object(caster,"%^BOLD%^%^RED%^You hurt yourself as your rage overwhelms you.");
    }
    call_out("rage",ROUND_LENGTH);
}

void dest_effect() {
   if(objectp(caster)) {
      if(caster->query_property("raged")){
         tell_object(caster,"%^GREEN%^The rage leaves you.%^RESET%^");
         tell_room(environment(caster),"%^GREEN%^The rage lifts from "+caster->QCN+".",caster);
         caster->add_attack_bonus(-1*mybonus);
         caster->add_damage_bonus(-1*mybonus);
         caster->remove_property("raged");
         caster->remove_property_value("spelled", ({TO}) );
         caster->use_stamina(25);
         remove_call_out("rage");
      }
   }
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
