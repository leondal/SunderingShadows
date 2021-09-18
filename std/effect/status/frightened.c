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
    set_name("effect_frightened");
}

void status_effect()
{
    int i, x;
    object * weapons;
    string * ids;

    if (target->query_property("effect_frightened") ||
        target->query_property("effect_panicked")) {
        TO->remove();
        return;
    }
    if (PLAYER_D->immunity_check(target, "fear")) {
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

    target->set_property("effect_frightened",1);

    tell_object(target,"%^BLUE%^You feel frightened.%^RESET%^");


    weapons = target->query_wielded();
    if (sizeof(weapons) && target->query_property("no disarm")) {
        tell_object(target, "%^CYAN%^You lose your grip on your weapons!%^RESET%^");
        tell_room(environment(target), "%^CYAN%^" + target->QCN + " drops " + target->QP + " weapons!%^RESET%^", target);
    }

    for (x = 0; x < sizeof(weapons); x++) {
        if (!objectp(weapons[x])) {
            continue;
        }
        ids = weapons[x]->query_id();
        if ((int)weapons[x]->query_property("enchantment") < 0) {
            continue;
        }
        target->force_me("unwield " + ids[0] + "");
        target->remove_property("disarm time");
        target->set_property("disarm time", time() + (ROUND_LENGTH * roll_dice(1, 2)));
    }

    power = target->query_level() / 12 + 1;

    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        target->add_skill_bonus(CORE_SKILLS[i], -power);
    }
    target->add_attack_bonus(-power);
    target->add_damage_bonus(-power);
    target->add_saving_bonus("all",-power);

    tell_object(target,"%^BOLD%^You flee before controlling yourself!%^RESET%^");
    tell_room(ENV(target),"%^BOLD%^"+target->QCN+" flees in fright!%^RESET%^",target);
    target->run_away();

    call_out("dest_effect",ROUND_LENGTH*duration,target);
}

void dest_effect(object ob)
{
    int i;
    if(objectp(ob))
    {
        tell_object(ob,"%^BLUE%^You no longer feel frightened.%^RESET%^");
        for(i=0;i<sizeof(CORE_SKILLS);i++)
            ob->add_skill_bonus(CORE_SKILLS[i],power);
        ob->add_attack_bonus(power);
        ob->add_damage_bonus(power);
        ob->add_saving_bonus("all",power);
        ob->remove_property("effect_frightened");
    }

    ::dest_effect();
}
