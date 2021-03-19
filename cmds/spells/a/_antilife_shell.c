#include <std.h>
#include <priest.h>
inherit SPELL;

int flag;

void create()
{
    ::create();
    set_spell_name("antilife shell");
    set_spell_level(([ "cleric" : 6, "druid" : 6 ]));
    set_domains("animal");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS antilife shell");
    set_damage_desc("perpetually removes living attackers for clevel / 18 + 1 rounds");
    set_description("This spell perpetually pushes away living opponents, trying to remove them from combat. It won't act together with similar spells, such as repulsion.");
}

int preSpell()
{
    if(caster->query_property("repulsion"))
    {
        tell_object(caster,"You are already under similar spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH) * (clevel / 18 + 1);
    tell_room(place,"%^GREEN%^As "+caster->QCN+" raises a field of magical force around "+caster->QP+".",caster);
    tell_object(caster,"%^GREEN%^You feel you're surrounded by a force field.");
    caster->set_property("repulsion",1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({"%^RESET%^%^GREEN%^ (in a field of force)%^RESET%^"}));
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
    attackers = target_filter(attackers);
    for(i=0;i<sizeof(attackers)&&i<6;i++)
    {
        if(!objectp(attackers[i]))
            continue;
        if(attackers[i]->is_undead())
            continue;
        if(attackers[i]->query("not living"))
            continue;

        tell_room(room,"%^GREEN%^"+attackers[i]->QCN+" is pushed away by a force field from "+caster->QCN+".%^RESET%^",({attackers[i]}));
        tell_object(attackers[i],"%^GREEN%^You are pushed away by a force field around "+caster->QCN+".%^RESET%^");
        attackers[i]->remove_attacker(caster);
        caster->remove_attacker(attackers[i]);
    }
    prepend_to_combat_cycle(place);
}

void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
        tell_room(environment(caster),"%^BOLD%^%^GREEN%^The force field around "+caster->QCN+" vanishes.%^RESET%^");
        caster->remove_property("repulsion");
        caster->remove_property_value("added short",({"%^RESET%^%^GREEN%^ (in a field of force)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
