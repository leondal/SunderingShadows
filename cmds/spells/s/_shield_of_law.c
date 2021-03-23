#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;

void create()
{
    ::create();
    set_spell_name("shield of law");
    set_spell_level(([ "cleric":8, "mage":8]));
    set_mystery("godclaw");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS shield of law");
    set_damage_desc("divine damage, 4 AC, 4 to all saves");
    set_description("You are surrounded by a dim blue glow, an aura that protects you and damages any unlawful creature that dares to attack you. This is a nimbus family of spells so it won't work together with similar spells.");
    set_property("magic",1);
    traveling_aoe_spell(1);
}

int preSpell()
{
    int align = caster->query_true_align();
    if (caster->query_property("nimbus")) {
        tell_object(caster, "You are still affected by shield of law or another nimbus spell.");
        return 0;
    }
    if (!(align == 1 || align == 2 || align == 3)) {
        tell_object(caster, "You are of improper alignment to use this spell!");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_object(caster,"%^BLUE%^Dim blue light envelopes you!");
    tell_room(place,"%^BLUE%^"+caster->QCN+" is suddenly surrounded by haze of dim blue light!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^BLUE%^ (in a dim blue haze)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    caster->add_saving_bonus("all",4);
    caster->add_ac_bonus(4);
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
    attackers = filter_array(attackers,(:$1->query_alignment()>3:));

    if(sizeof(attackers))
    {
        define_base_damage(0);
        tell_room(place,"%^BLUE%^The lawful energies around "+caster->QCN+" forcefully repels "+caster->QP+" enemies!",({caster,target}));
        tell_object(caster,"%^BLUE%^The lawful energies around you forcefully repels your enemies!");
        for(i=0;i<sizeof(attackers);i++){
            if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
            tell_object(attackers[i],"%^BOLD%^%^BLUE%^You are painfully repelled by the lawful energies as you strike "+caster->QCN+"!");
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"divine");
        }
    }
    prepend_to_combat_cycle(place);
}

void dest_effect()
{
    remove_call_out("room_check");
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^%^BLUE%^The haze around you fades.");
        caster->remove_property("nimbus");
        caster->add_ac_bonus(-4);
        caster->add_saving_bonus("all",-4);
	    caster->remove_property_value("added short",({"%^BLUE%^ (in a dim blue haze)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
