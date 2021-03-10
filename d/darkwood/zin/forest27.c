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
    set("short", "Northwest shore of Darklake");
    set("long", "A break in the forest is a welcome site.  This appears "+  
                "to be the northwest shoreline of a small lake with "+
                "waters as dark as tar.  The break in the forest trees "+
                "has forced the canopy of branches overhead to part ever "+
                "so slightly.  Yet, as slivers of light pour through the "+
                "breaks in the twisted branches and dark leaves, it is "+
                "absorbed by the polished black surface of the lake "+
                "destroy any warmth and creating a defeated atmosphere.  "+
                "The shoreline continues to the south and east, while "+
                "slight openings in the trees to the northwest and "+
                "west lead deeper into the clutches of the forest.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "leaves": "They are rotting and cover the entire ground.",
        "lake": "Its waters are jet black and contain a polished surface.",
    ]) );
    set_exits( ([
        "south": ROOM_DIR+"forest28",
        "west": ROOM_DIR+"forest26",
        "east": ROOM_DIR+"forest18",
        "northwest": ROOM_DIR+"forest24",
    ]) );
}
