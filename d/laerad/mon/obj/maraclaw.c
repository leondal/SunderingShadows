//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"claw"}));
    set_name("Mara's claw");
    set_short("Mara's claw");
    set_long("A large stone claw from a Mara.");
    set_weight(15);
    set_size(2);
    set("value",1);
    set_wc(3,4);
    set_large_wc(3,4);
    set_type("slashing");
    set_property("monsterweapon",1);
}
