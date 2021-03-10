#include <std.h>
#include <magic.h>
#include <skills.h>
#include <daemons.h>

#pragma strict_types

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_cowering");
}

void status_effect()
{
    int i, x;
    object weapons;
    string exits;

    if (target->query_property("effect_cowering")) {
        TO->remove();
        return;
    }

    if (LIVING_D->immunity_check(target, "fear")) {
        TO->remove();
        return;
    }

    if (target->query_property("mind_immunity")) {
        int roll = roll_dice(1, 20);
        if (roll < target->query_property("mind_immunity") && roll != 20) {
            tell_object(target,"%^BLUE%^Through your will you manage to avoid fears, at a price.");
            target->cause_typed_damage(target,target->return_target_limb(),roll_dice(target->query_level(), 6),"mental");
            TO->remove();
            return;
        }
    }

    target->set_property("effect_cowering",1);

    tell_object(target,"%^BLUE%^You are cowering in fear.%^RESET%^");

    power = target->query_level()/6+1;

    target->add_ac_bonus(-power);
    tell_object(target,"%^BOLD%^%^BLUE%^Unable to contain your terror, you cower!%^RESET%^");
    tell_room(ENV(target),"%^BOLD%^%^BLUE%^"+target->QCN+" cowers in terror!%^RESET%^",target);
    target->set_paralyzed(duration*8,"%^BLUE%^You cannot contain your fear to do that!");

    call_out("dest_effect",ROUND_LENGTH*duration);
}

void dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^BLUE%^You are no longer cowering.%^RESET%^");
        target->add_ac_bonus(power);
        target->remove_property("effect_cowering");
    }

    ::dest_effect();
}
