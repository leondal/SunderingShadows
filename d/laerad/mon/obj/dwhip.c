//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"whip"}));
    set_name("Whip of terror");
    set_short("Whip of terror");
    set_long("Qualtatoth's whip of terror.");
    set_weight(5);
    set_size(2);
    set("value",1);
    set_wc(1,6);
    set_large_wc(1,8);
    set_type("bludgeoning");
    set_property("monsterweapon",1);
}
