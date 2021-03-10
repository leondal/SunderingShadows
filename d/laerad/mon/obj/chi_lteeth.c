//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"teeth"}));
    set_name("Chimera's lion teeth");
    set_short("Chimera's lion teeth");
    set_long("The teeth from the lion head of a Chimera.");
    set_weight(10);
    set_size(2);
    set("value",1);
    set_wc(2,4);
    set_large_wc(2,4);
    set_type("piercing");
    set_property("monsterweapon",1);
}
