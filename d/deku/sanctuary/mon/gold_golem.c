#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("golem");
    set_id(({ "golem", "statue", "gold golem", "gold statue" }));
    set_short("%^BOLD%^%^YELLOW%^Gold Golem%^RESET%^");
    set_long(
        "This statue stands at over sixteen feet tall and is carved in the likeness of" +
        " a massive man. Its arms, legs, and torso are chiseled into fine curves to" +
        " depict a man of power and strength."
        );
    set_class("fighter");
    set_guild_level("fighter", 20);
    set_race("golem");
    set_body_type("human");
    set_hd(20, 10);
    set_alignment(5);
    set_max_hp(400);
    set_hp(400);
    set_overall_ac(-6);
    set_mob_magic_resistance("average");
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("no bows", 1);
    set_property("no paralyze", 1);
    set_property("no poison", 1);
    set_size(3);
    set("aggressive", 30);
    set_exp(24000);
    add_limb("right fist", "right arm", 0, 0, 0);
    add_limb("left fist", "left arm", 0, 0, 0);
    set_wielding_limbs(({ "right fist", "left fist" }));
    set_attack_limbs(({ "right fist", "left fist" }));
    set_base_damage_type("bludgeoning");
    set_attacks_num(2);
    set_damage(1, 20);
    set_stats("strength", 25);
    set_stats("dexterity", 18);
    set_max_level(23);
}
