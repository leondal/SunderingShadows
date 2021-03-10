//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"claw"}));
    set_name("Chimera's claw");
    set_short("Chimera's claw");
    set_long("A nasty claw from a Chimera.");
    set_weight(5);
    set_size(2);
    set("value",1);
    set_wc(1,3);
    set_large_wc(1,3);
    set_type("slashing");
    set_property("monsterweapon",1);
}
