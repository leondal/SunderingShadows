//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"teeth"}));
    set_name("Chimera's dragon teeth");
    set_short("Chimera's dragon teeth");
    set_long("The teeth from the dragon head of a Chimera.");
    set_weight(15);
    set_size(2);
    set("value",1);
    set_wc(3,4);
    set_large_wc(3,4);
    set_type("piercing");
    set_property("monsterweapon",1);
}
