// d_robe.c

#include <std.h>

inherit "/std/armour";
inherit "/std/bag_logic";

void create() {
    ::create();
    set_name("robe");
    set("id", ({ "robe","cloak", "armor", "d_robex" }) );
    set("short", "A robe");
    set_long(
"    This is the simplest type of armor, fashioned from quilted \n"+
"layers of cloth and batting. It tends to get hot, and after a time \n"+
"becomes foul with sweat,grime,lice and fleas. This robe appears to \n"+
"have a number of pockets sown into it. \n"+
"    It looks like you can put stuff in the robe.\n"
       );
    set_weight(10);
    set("value", 4);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(1);
    set_max_internal_encumbrance(100);
}

