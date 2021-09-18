#include <std.h>
#include <magic.h>
#include <skills.h>
#include <daemons.h>

#pragma strict_types

inherit STATUS;

void create()
{
    ::create();
    set_name("effect_exhausted");
}

void status_effect()
{
    int i;
    object * effects;

    if (!objectp(target)) {
        TO->remove();
        return;
    }

    if (target->query_property("effect_exhausted")) {
        TO->remove();
        return;
    }

    if (PLAYER_D->immunity_check(target, "fatigue")) {
        TO->remove();
        return;
    }

    effects = target->query_property("status_effects");

    if (sizeof(effects)) {
        object effect;

        if (sizeof(effects))
            foreach(effect in effects)
            {
                if (!objectp(effect)) {
                    continue;
                }

                if (effect->query_name() == "effect_fatigued") {
                    effect->dest_effect();
                }
            }
    }

    target->set_property("effect_exhausted", 1);

    tell_object(target, "%^RED%^You feel exhaustion.%^RESET%^");

    target->add_stat_bonus("strength", -6);
    target->add_stat_bonus("dexterity", -6);

    call_out("dest_effect", ROUND_LENGTH * duration, target);
}

void dest_effect(object ob)
{
    if(!objectp(ob))
    {
        ::dest_effect();
        return;
    }

    tell_object(ob,"%^RED%^You no longer feel exhausted.%^RESET%^");
    ob->add_stat_bonus("strength", 6);
    ob->add_stat_bonus("dexterity", 6);
    ob->remove_property("effect_exhausted");
    
    if(objectp(this_object()))
        ::dest_effect();
}
