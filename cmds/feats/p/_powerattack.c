#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("MeleeDamage");
    feat_name("powerattack");
    feat_prereq("Strength 13");
    feat_syntax("powerattack offensive|defensive|max|min|check");
    feat_desc("The PowerAttack feat allows the character to shift their stance so that their attacks do more damage but it makes their attacks less likely to hit."
        + "\n"
        + "\nThis feat shift values between attack and damage bonuses."
        + "\nYou can use this feat once and one aditional time for every 4 character levels to a max bonus of 5.");
        set_target_required(0);
    set_required_for(({ "shatter","sunder","rush" }));
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((int)ob->query_base_stats("strength") < 13) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_powerattack(string str)
{
    object feat;
    if (!objectp(TP)) { return 0; }
    if (str) str = lower_case(str);
    if (str != "offensive" &&
        str != "defensive" &&
        str != "max" &&
        str != "min") {
        str = "check";
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

int check_my_status(object ob)
{
    if (!objectp(ob)) { return 0; }

    if (ob->query_bound() || ob->query_unconscious() || ob->query_tripped())
    {
        tell_object(ob, "You are unable to move well enough to do that.");
        return 0;
    }
    return 1;
}

void execute_feat()
{
    int bonus, maxbonus;

    if (!check_my_status(caster))
    {
        dest_effect();
        return;
    }

    ::execute_feat();

    bonus = (int)caster->query_property("power_attack");
    maxbonus = (int)caster->query_base_character_level() / 4 + 1;
    maxbonus = (maxbonus < 5 ? maxbonus : 5);

    switch (arg)
    {
    case "offensive":
        if (bonus == maxbonus)
        {
            tell_object(caster, "%^RESET%^%^MAGENTA%^You can't make your attacks anymore powerful!%^RESET%^");
            dest_effect();
            return;
        }
        caster->set_property("power_attack", 1);
        caster->add_damage_bonus(1);
        caster->add_attack_bonus(-1);
        tell_object(caster, "%^BOLD%^%^RED%^You shift your stance to make your attacks more powerful!%^RESET%^");
        dest_effect();
        break;
    case "defensive":
        if (!bonus)
        {
            tell_object(caster, "%^RESET%^%^MAGENTA%^You can't make your attacks any less powerful!%^RESET%^");
            dest_effect();
            return;
        }
        caster->set_property("power_attack", - 1);
        caster->add_damage_bonus(-1);
        caster->add_attack_bonus(1);
        tell_object(caster, "%^BOLD%^%^GREEN%^You shift your stance to make your attacks less powerful!%^RESET%^");
        dest_effect();
        break;
    case "max":
        caster->set_property("power_attack", maxbonus - bonus);
        caster->add_damage_bonus(maxbonus - bonus);
        caster->add_attack_bonus(bonus - maxbonus);
        tell_object(caster, "%^BOLD%^%^RED%^You shift your stance to make your attacks more powerful!%^RESET%^");
        dest_effect();
        break;
    case "min":
        caster->set_property("power_attack", - bonus);
        caster->add_damage_bonus(- bonus);
        caster->add_attack_bonus(bonus);
        tell_object(caster, "%^BOLD%^%^GREEN%^You shift your stance to make your attacks less powerful!%^RESET%^");
        dest_effect();
        break;
    case "check":

        tell_object(caster, "%^RESET%^%^GREEN%^You have shifted %^MAGENTA%^" + bonus + " %^RESET%^%^GREEN%^points into " +
            "powerattack.%^RESET%^");
        dest_effect();
        return;
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
