//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"spear"}));
    set_name("Ninja spear");
    set_short("Ninja spear");
    set_long("The Shadow Warrior's ninja spear");
    set_weight(10);
    set_size(2);
    set("value",1);
    set_wc(3,6);
    set_large_wc(3,6);
    set_type("piercing");
    set_property("monsterweapon",1);
    set_property("enchantment",2);
}
