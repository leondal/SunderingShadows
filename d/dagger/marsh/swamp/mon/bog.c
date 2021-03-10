#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

int level;

void create()
{
    :: create();
    set_name("wraith");
    set_id(({ "bog wraith", "wraith" }));
    set_short("%^RESET%^%^GREEN%^Bog wraith%^RESET%^");
    set_long("A shadowy humanoid shape which floats above the marsh. Its cold "
             "green eyes gaze deep into your soul, as if searching for your inner "
             "being.");
    set_gender("male");
    set_property("magic", 1);

    set_class("fighter");

    level = roll_dice(1, 10) + 20;

    set_hd(level, 12);
    set_level(level);
    set_max_level(36);
    set_size(2);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "right hand", "left hand" }));
    set_overall_ac(10 - level);
    set_body_type("humanoid");
    set_race("undead");
    set_guild_level("fighter", level);
    set_mlevel("fighter", level);
    set_alignment(6);
    set("aggressive", random(10) + 7);
    set_property("magic resistance", level);
    set_new_exp(level + 5, "high");
    set_max_hp(level * 16 + 50);
    set_hp(level * 16 + 50);
    add_money("gold", random(1000));
    set_emotes(1, ({ "%^BLUE%^The wraith reaches out towards you.%^RESET%^",
                     "%^GREEN%^The bog wraith gazes deep into your soul.",
                     "The bog wraith floats towards you.",
                     "%^MAGENTA%^Bog Wraith says: %^RESET%^Search not for Demongate "
                     "Tower, lest you wish to join me in my eternal plight!", }), 0);
    set_funcs(({ "absorb" }));
    set_func_chance(40);
    set_property("no paralyze", 1);
    set_property("no tripped", 1);
    set_speed(50);
    set_moving(1);
    set_nogo(({ ROOMS "m44", ROOMS "m44.c" }));
    set_stats("strength", 25);
    set_stats("dexterity", 25);
    set_stats("constitution", 25);
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("charisma", 25);
    set_attacks_num(level / 7);
    set_damage(2, (level / 2));
    add_attack_bonus(roll_dice(1, 6));
    add_damage_bonus(roll_dice(1, 6));
}

void absorb(object targ)
{
    int dam;
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }

    dam = (int)targ->query_hp() / 3;

    if (FORT(targ, -1 * (level - 5))) {
        dam = dam / 2;
    }

    tell_room(ETO, "%^BOLD%^%^GREEN%^The bog wraith's eyes blaze with a bright "
              "%^RED%^red light%^GREEN%^ as he strikes " + targ->QCN + "!%^RESET%^", targ);
    tell_object(targ, "%^BOLD%^%^GREEN%^The shadow wraith's eyes blaze with a bright "
                "%^RED%^red light%^GREEN%^ as he strikes you!\n%^RED%^An intense chill fills "
                "your soul as a portion of your life is drained away!%^RESET%^");

    targ->cause_typed_damage(targ, targ->return_target_limb(),dam,"negative energy");
    TO->add_hp(dam);
}
