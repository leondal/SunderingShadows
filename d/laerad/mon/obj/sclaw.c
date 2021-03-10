//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"claw"}));
    set_name("Ninja claw");
    set_short("Ninja claw");
    set_long("A nasty ninja claw.");
    set_weight(10);
    set_size(1);
    set("value",1);
    set_wc(1,12);
    set_large_wc(1,10);
    set_type("slashing");
    set_property("monsterweapon",1);
    set_property("enchantment",1);
}
