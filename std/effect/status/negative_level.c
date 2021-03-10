#include <std.h>
#include <magic.h>
#include <skills.h>

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_negative_level");
}

int status_effect()
{
    int i;

    if (target->query_property("effect_negative_level") > 4) {
        TO->remove();
        return;
    }

    tell_object(target, "%^BLUE%^You feel weakened.%^RESET%^");

    power = 1;

    if (query_param()) {
        power = query_param();
    }

    target->set_property("effect_negative_level", power);

    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        target->add_skill_bonus(CORE_SKILLS[i], -power);
    }

    target->add_attack_bonus(-power);
    target->add_saving_bonus("all", -power);
    target->set_property("empowered", -power);

    call_out("dest_effect", ROUND_LENGTH * duration);
    return 1;
}

int dest_effect()
{
    int i;
    if (objectp(target)) {
        target->set_property("effect_negative_level", -power);

        if (target->query_property("effect_negative_level")) {
            tell_object(target, "%^BLUE%^You feel less weakened.");
        } else {
            tell_object(target, "%^BLUE%^You no longer feel weakened.%^RESET%^");
        }

        for (i = 0; i < sizeof(CORE_SKILLS); i++) {
            target->add_skill_bonus(CORE_SKILLS[i], power);
        }

        target->add_attack_bonus(power);
        target->add_saving_bonus("all", power);
        target->set_property("empowered", power);
    }
    ::dest_effect();
    return 1;
}
