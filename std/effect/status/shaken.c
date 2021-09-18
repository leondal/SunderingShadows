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
    set_name("effect_shaken");
}
void status_effect()
{
    int i;
    if (target->query_property("effect_shaken")) {
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
            tell_object(target,"%^CYAN%^Through your will you manage to avoid being shaken, at a price.");
            target->cause_typed_damage(target,target->return_target_limb(),roll_dice(target->query_level(), 6),"mental");
            TO->remove();
            return;
        }
    }

    target->set_property("effect_shaken", 1);

    tell_object(target, "%^ORANGE%^You feel shaken.%^RESET%^");
    tell_room(ENV(target), "%^ORANGE%^" + target->QCN + " looks shaken.", target);

    power = target->query_level() / 12 + 1;

    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        target->add_skill_bonus(CORE_SKILLS[i], -power);
    }
    target->add_attack_bonus(-power);
    target->add_saving_bonus("all", -power);

    call_out("dest_effect", ROUND_LENGTH * duration, target);
}
void dest_effect(object ob)
{
    int i;
    if (objectp(ob)) {
        tell_object(ob, "%^ORANGE%^You no longer feel shaken.%^RESET%^");
        tell_room(ENV(ob), "%^ORANGE%^" + ob->QCN + " no longer looks shaken.", ob);
        for (i = 0; i < sizeof(CORE_SKILLS); i++) {
            ob->add_skill_bonus(CORE_SKILLS[i], power);
        }
        ob->add_attack_bonus(power);
        ob->add_saving_bonus("all", power);
        ob->remove_property("effect_shaken");
    }

    ::dest_effect();
}
