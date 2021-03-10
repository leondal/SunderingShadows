#include <std.h>
#include <magic.h>
#include <skills.h>

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_sickened");
}
int status_effect()
{
    int i;

    if (target->query_property("effect_sickened") > 4) {
        TO->remove();
        return;
    }

    target->set_property("effect_sickened", 1);

    tell_object(target, "%^BLUE%^You feel sickened and disgusted.%^RESET%^");
    tell_room(ENV(target), "%^BLUE%^" + target->QCN + "'s face turns green," + target->QS + " look sickened.", target);

    power = target->query_level() / 12 + 1;

    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        target->add_skill_bonus(CORE_SKILLS[i], -power);
    }
    target->add_attack_bonus(-power);
    target->add_damage_bonus(-power);
    target->add_saving_bonus("all", -power);

    call_out("dest_effect", ROUND_LENGTH * duration);
    return 1;
}
int dest_effect()
{
    int i;
    if (objectp(target)) {
        target->set_property("effect_sickened", -1);

        if (target->query_property("effect_sickened")) {
            tell_object(target,"%^BLUE%^You feel less sickened.");
        } else {
            tell_object(target, "%^BLUE%^You no longer feel sickened.%^RESET%^");
        }
        tell_room(ENV(target), "%^BLUE%^" + target->QCN + " no longer looks sickened.", target);
        for (i = 0; i < sizeof(CORE_SKILLS); i++) {
            target->add_skill_bonus(CORE_SKILLS[i], power);
        }
        target->add_attack_bonus(power);
        target->add_damage_bonus(power);
        target->add_saving_bonus("all", power);

    }
    ::dest_effect();
    return 1;
}
