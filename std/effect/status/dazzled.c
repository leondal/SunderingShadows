#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_dazzled");
}
void status_effect()
{
    int i;

    if (target->query_property("effect_dazzled")) {
        TO->remove();
        return;
    }

    target->set_property("effect_dazzled", 1);

    tell_object(target, "%^ORANGE%^You see the stars and are dazzled.%^RESET%^");

    power = target->query_level() / 18 + 1;

    target->add_skill_bonus("perception", -power);
    target->add_skill_bonus("thievery", -power);
    target->add_attack_bonus(-power);

    call_out("dest_effect", ROUND_LENGTH * duration, target);
}
void dest_effect(object ob)
{
    int i;
    if (objectp(ob)) {
        tell_object(ob, "%^ORANGE%^You no longer are dazzled.%^RESET%^");
        ob->add_skill_bonus("perception", power);
        ob->add_skill_bonus("thievery", power);
        ob->add_attack_bonus(power);
        ob->remove_property("effect_shaken");
    }

    ::dest_effect();
}
