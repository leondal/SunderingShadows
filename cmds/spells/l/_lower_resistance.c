#include <std.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("lower resistance");
    set_spell_level(([ "classless" : 5 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS lower resistance on TARGET");
    set_description("This will temporarily pull from the target some quantity of magic resistance.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
                        "mage" : ([ "iron rod" : 1, ]),
                    ]));
}

/*
 * DO NOT REMOVE THIS SPELL
 * USED BY NPCS
 */

string query_cast_string()
{
    return "%^MAGENTA%^" + caster->QCN + " raises the iron rod and starts to chant.";
}

void spell_effect(int prof)
{
    int resistance, lower;

    if (!objectp(target)) {
        return;
    }
    if (!objectp(caster)) {
        return;
    }
    if (!caster->ok_to_kill(target)) {
        dest_effect();
        return;
    }
    tell_room(place, "%^MAGENTA%^You watch as " + caster->QCN + " starts to counter the counter magic.", ({ caster, target }));
    tell_object(target, "%^MAGENTA%^" + caster->QCN + " points an iron bar toward you chanting arcane phrases of disenchantment.");
    tell_object(caster, "%^MAGENTA%^You point an iron bar at " + target->QCN + " and start to chant feeling the pull of power fighting.");

    if (target->query_property("lowered resistance")) {
        tell_object(caster, "%^BOLD%^The spell is repelled forcibly.");
        dest_effect();
        return;
    }
    if (!target->query_property("magic resistance")) {
        tell_object(caster, "That creature has no resistance.");
        dest_effect();
        return;
    }

//
    resistance = target->query_property("magic resistance");

    tell_room(place, "%^MAGENTA%^In a great forceful pull you can see power yanked in the iron bar.");
    lower = clevel / 20;
    target->set_property("magic resistance", (-1 * lower));
    target->set_property("lowered resistance", 1);
    call_out("undo", 80 + clevel * 8, lower);
}

void undo(int lower)
{
    if (!target || !objectp(target)) {
        TO->remove();
        return;
    }
    if (target->query_property("lowered resistance")) {
        target->set_property("magic resistance", lower);
        target->remove_property("lowered resistance");
    }

    tell_room(environment(target), "%^MAGENTA%^ You see the wave of incoming power returning to " + target->QCN + ".");
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
