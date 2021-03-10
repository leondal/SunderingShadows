#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Kitchen and Pantry");
    set_long("The kitchen is in disarray. Pots and pans have been scattered about, the knife "+
"blocks emptied, and the large ovens are cold. Only dust and cobwebs line the pantries, which "+
"have all been raided and emptied, so that not even a single crumb is left behind.\n");
     set_smell("default","The scent of foods gone stale pervade the air.");
    set_exits(([
       "west" : "/d/deku/fortress/hall_din",
       "north" : "/d/deku/fortress/storage"
    ] ));
    set_items(([
       "shelfs" : "The shelves are completely empty, as if nobody has cooked here for a very long time."
    ] ));
}
