#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;

void create()
{
    ::create();
    set_spell_name("energy retort");
    set_spell_level(([ "psion" : 3 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS energy retort");
    set_damage_desc("mental damage");
    set_description("This power will generate psychic energy around the psion, enveloping him in a crackling field that " +
"can harm attackers.  Once each round, the psion automatically lashes out at one of his foes, striking him with energy.  " +
"The duration of this power grows with the psion.");
    set_property("magic",1);
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string()
{
   return "%^ORANGE%^"+caster->QCN+" focuses, causing the area "+
      "to crackle with energy.";
}

int preSpell()
{
    if (caster->query_property("nimbus"))
    {
        tell_object(caster, "You are still affected by another travelling AOE spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_room(place,"%^YELLOW%^"+caster->QCN+" suddenly glows within a field of energy!", ({ caster }));
    tell_object(caster,"%^YELLOW%^You feel electrified as your skin crackles with energy!");

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^BOLD%^%^YELLOW%^ (surrounded by crackling energy)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check",ROUND_LENGTH*2);
    return;
}

void execute_attack(){
    object *attackers;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    place      = environment(caster);
    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }

    attackers = filter_array(caster->query_attackers(),(:objectp($1):));
    attackers = filter_array(attackers,(:$1->is_living():));

    if(sizeof(attackers))
    {
        define_base_damage(0);
        tell_room(place,"%^BOLD%^%^YELLOW%^The crackling energy around "+caster->QCN+" lashes out at "+caster->QP+" enemies!",({caster,target}));
        tell_object(caster,"%^BOLD%^%^YELLOW%^The crackling energy around you lashes out at your enemies!");
        for(i=0;i<sizeof(attackers);i++){
            if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
            tell_object(attackers[i],"%^BOLD%^%^WHITE%^You are scorched by the psychic energy as you strike "+caster->QCN+"!");
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"mental");
        }
    }
    prepend_to_combat_cycle(place);
}

void dest_effect()
{
    remove_call_out("room_check");
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The crackling energy around you fades.");
        caster->remove_property("nimbus");
	    caster->remove_property_value("added short",({"%^BOLD%^%^YELLOW%^ (surrounded by crackling energy)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
