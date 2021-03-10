//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"teeth"}));
    set_name("Manticore's teeth");
    set_short("Manticore's teeth");
    set_long("The teeth from a nasty Manticore");
    set_weight(10);
    set_size(2);
    set("value",1);
    set_wc(1,8);
    set_large_wc(1,8);
    set_type("piercing");
    set_property("monsterweapon",1);
}
