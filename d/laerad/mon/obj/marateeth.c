//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"teeth"}));
    set_name("Mara's teeth");
    set_short("Mara's teeth");
    set_long("The teeth from the massive stone beast, Mara.");
    set_weight(20);
    set_size(2);
    set("value",1);
    set_wc(1,6);
    set_large_wc(1,6);
    set_type("piercing");
    set_property("monsterweapon",1);
}
