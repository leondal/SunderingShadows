//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"horn"}));
    set_name("Undead Beast's horn");
    set_short("Undead Beast's horn");
    set_long("A nasty pair of horns from an Undead Beast.");
    set_weight(15);
    set_size(2);
    set("value",1);
    set_wc(3,8);
    set_large_wc(3,8);
    set_type("piercing");
    set_property("monsterweapon",1);
}
