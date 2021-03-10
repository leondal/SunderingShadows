//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/06/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "It smells of decay and horrid death.");
    set_listen("default", "It is deathly quiet.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Southeast shoreline of Darklake");
    set("long", "The forest finally breaks in front of you.  You find "+
                "yourself standing on the southeast shoreline of a "+
                "small lake with waters as dark as tar.  The break in "+
                "the forest trees has forced the canopy of branches "+
                "overhead to part ever so slightly.  Yet, as slivers of "+
                "light pour through the breaks in the twisted branches "+
                "and dark leaves, it is absorbed by the polished black "+ 
                "surface of the lake createing a defeated atmosphere.  "+
                "A small river bleeds the tar black waters of the lake "+
                "to the south.  The shoreline continues to the north and "+ 
                "west, while slight breaks in the trees to the south "+
                "and east lead deeper into the clutches of the forest.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "leaves": "They are rotting and cover the entire ground.",
        "stream": "Its dark surface mirrors a twisted version of yourself.",
        "lake": "Its waters are jet black and contain a polished surface.",
    ]) );
    set_exits( ([
        "north": ROOM_DIR+"forest18",
        "south": ROOM_DIR+"forest30",
        "west": ROOM_DIR+"forest28",
        "east": ROOM_DIR+"forest17",
    ]) );
}

void init(){
  ::init();
  do_random_encounters(({MON_DIR+"nymph",MON_DIR+"dwarf",MON_DIR+"goblin"}),60,4);
}
