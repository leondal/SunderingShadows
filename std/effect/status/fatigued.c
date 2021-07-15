#include <std.h>
#include <magic.h>
#include <skills.h>
#include <daemons.h>

#pragma strict_types

inherit STATUS;

void create()
{
    ::create();
    set_name("effect_fatigued");
}

void status_effect()
{
    int i;

    if (!objectp(target)) {
        return;
    }

    if (target->query_property("effect_exhausted") ||
        target->query_property("effect_fatigued")) {
        TO->remove();
        return;
    }

    if (PLAYER_D->immunity_check(target, "fatigue")) {
        tell_object(target, "You are immune to fatigue.");
        TO->remove();
        return;
    }

    target->set_property("effect_fatigued",1);

    tell_object(target,"%^RED%^You feel tired and fatigued.%^RESET%^");

    target->add_stat_bonus("strength", -2);
    target->add_stat_bonus("dexterity", -2);

    call_out("dest_effect",ROUND_LENGTH*duration,target);
}

void dest_effect(object ob)
{
    if(!objectp(ob))
    {
        ::dest_effect();
        return;
    }

    tell_object(ob,"%^RED%^You no longer are fatigued.%^RESET%^");
    ob->add_stat_bonus("strength", 2);
    ob->add_stat_bonus("dexterity", 2);
    ob->remove_property("effect_fatigued");
    
    if(objectp(this_object()))
        ::dest_effect();
}

