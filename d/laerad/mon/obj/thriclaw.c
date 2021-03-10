//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"claw"}));
    set_name("Thri-Kreen's claw");
    set_short("Thri-Kreen's claw");
    set_long("A sharp claw from a noble Thri-Kreen.");
    set_weight(5);
    set_size(2);
    set("value",1);
    set_wc(1,4);
    set_large_wc(1,4);
    set_type("slashing");
    set_property("monsterweapon",1);
}
