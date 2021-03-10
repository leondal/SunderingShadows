#include <std.h>;

inherit "/std/armour.c";

void create(){
    ::create();
    set_name("gauntlets");
    set_id(({"gauntlets","gloves","glove","mesh"}));
    set("short","black mesh gauntlets");
    set("long","A set of thick alloy mesh gauntlets.");
    set_type("clothing");
    set_limbs(({"right arm","left arm"}));
    set_weight(5);
    set_value(100);
}
