#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("a large bloated rat");
    set_id(({"rat","large rat", "bloated rat", "large bloated rat", "chsaideoozefood"}));
    set_short("%^BOLD%^%^BLACK%^a large bloated rat%^RESET%^");
    set_long("%^ORANGE%^This %^BOLD%^%^BLACK%^dirty black rat %^RESET%^%^ORANGE%^stares up at you with his beady "
    "little eyes.  His litte body is exceptionally bloated from what is suspect is an abundance "+
    "of food. It is also covered with filthy, greasy hair.  A %^BOLD%^%^MAGENTA%^long white "
    "tail%^RESET%^%^ORANGE%^ twitches anxiously as he bares his teeth at you.%^RESET%^");
    set_race("rat");
    set_body_type("quadruped");
    set_gender("male");
    set_size(1);
    set("aggressive",25);
    set_property("swarm",1);
    set_level(12);
    set_class("fighter");
    set_mlevel("fighter",12);
    set_hp(55 + random(35));
    set_new_exp(12, "very low");
    set_max_level(20);
    set_damage(1,6);
    set_attacks_num(3);
    set_base_damage_type("piercing");
    set_attack_limbs(({"right forepaw","left forepaw","mouth"}));
    set_ac(8);
    set_alignment(5);
    add_money("gold",random(45)+45);
    
    set_stats("strength", 17);
    set_stats("intelligence", 14);
    set_stats("wisdom", 1);
    set_stats("constitution", 14);
    set_stats("dexterity", 14);
    set_stats("charisma", 1);
    set_moving(1);
    set_speed(25);
    set_nogo(({OE}));
}
