#include <std.h>
#include <priest.h>
inherit SPELL;

int flag;

void create()
{
    ::create();
    set_spell_name("undeath ward");
    set_spell_level(([ "cleric" : 5, "inquisitor" : 4, "mage" : 6]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS repulsion");
    set_damage_desc("removes undead from combat or damages them");
    set_description("This spell pushes undead creatures away from you, removing them from combat. Undead that makes the save will take damage instead.");
    set_save("will");
    traveling_aoe_spell(1);
}

int preSpell()
{
    if(caster->query_property("repulsion"))
    {
        tell_object(caster,"You are already under this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 2) * clevel;
    tell_room(place,"%^WHITE%^As "+caster->QCN+" raises a field of magical force around "+caster->QP+".",caster);
    tell_object(caster,"%^WHITE%^You feel you're surrounded by a force field.");
    caster->set_property("repulsion",1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({"%^RESET%^%^WHITE%^ (bathed in silver light)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
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


void execute_attack()
{
    object *attackers,room;
    int i;

    ::execute_attack();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    room      = environment(caster);
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);
    for(i=0;i<sizeof(attackers)&&i<6;i++)
    {
        if(!do_save(attackers[i],4))
        {
            tell_room(room,"%^WHITE%^"+attackers[i]->QCN+" is pushed away by a force field from "+caster->QCN+".%^RESET%^",({attackers[i]}));
            tell_object(attackers[i],"%^WHITE%^You are pushed away by a force field around "+caster->QCN+".%^RESET%^");
            attackers[i]->remove_attacker(caster);
            caster->remove_attacker(attackers[i]);
        }
        else
        {
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"silver");
            tell_object(attackers[i],"%^WHITE%^%^BOLD%^You're rebuked by the silver light.%^RESET%^");
        }
    }
    prepend_to_combat_cycle(place);
}

void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
        tell_room(environment(caster),"%^BOLD%^%^WHITE%^The force field around "+caster->QCN+" vanishes.%^RESET%^");
        caster->remove_property("repulsion");
        caster->remove_property_value("added short",({"%^RESET%^%^WHITE%^ (bathed in silver light)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
