//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"horn"}));
    set_name("Chimera's horn");
    set_short("Chimera's horn");
    set_long("A nasty pair of horns from a Chimera.");
    set_weight(10);
    set_size(2);
    set("value",1);
    set_wc(1,4);
    set_large_wc(1,4);
    set_type("piercing");
    set_property("monsterweapon",1);
}
