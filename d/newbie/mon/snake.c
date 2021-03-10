#include <std.h>
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("snake");
    set_id(({ "snake", "giant snake", "black snake" }));
    set_short("A giant black snake");
    set_long("%^BOLD%^%^BLACK%^This snake is several times the size of a normal black snake.  It's about six foot long and has fangs as long as a human's finger.\n");
    set_race("snake");
    set_body_type("snake");
    set_gender("female");
    set_size(1);
    set("aggressive", 20);
    set_hd(1, 2);
    set_level(1);
    set_class("fighter");
    set_mlevel("fighter", 1);
    set_max_hp(20);
    set_hp(random(10) + 10);
    set_exp(25);
    set_damage(1, 3);
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "mouth", "tail", "torso" }));
    set_ac(10);
    set_alignment(5);
    add_money("gold", random(10) + 5);
    add_money("silver", random(20));
    set_stats("intelligence", 2);
    set_stats("wisdom", 2);
    set_stats("strength", 5);
    set_stats("charisma", 2);
    set_stats("dexterity", 14);
    set_stats("constitution", 14);
    set_new_exp(1, "very low");
}
