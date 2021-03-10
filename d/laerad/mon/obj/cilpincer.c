//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"pincer"}));
    set_name("Cildabrin's pincer");
    set_short("Cildabrin's pincer");
    set_long("A nasty scorpion pincer from a Cildabrin.");
    set_weight(10);
    set_size(2);
    set_value(0);
    set_wc(1,12);
    set_large_wc(1,12);
    set_type("slashing");
    set_property("monsterweapon",1);
}
