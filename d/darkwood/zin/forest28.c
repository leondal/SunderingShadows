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
    set("short", "Southwest shoreline of Darklake");
    set("long", "A breeze tears through through your clothing and "+
                "chills you to the bone.  You feel its not the coldness "+
                "of the breeze, but rather the feeling of death which "+
                "rides it.  The trees of Darkwood Forest stands silently "+
                 "to the south and west in a dense knot of forbidding any "+
                "passage.  The death black waters of the lake appears "+
                "almost like glass as it absorbs any light that may "+
                "pass through the tiny breaks in the canopy of limbs "+
                "and leaves that are everpresent in this forest.  Your "+
                "can only move along the shore line which runs north "+
                "and east.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "limbs": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "leaves": "They are rotting and cover the entire ground.",
        "lake": "Its waters are jet black and contain a polished surface.",
    ]) );
    set_exits( ([
        "north": ROOM_DIR+"forest27",
        "east": ROOM_DIR+"forest29",
    ]) );
}

void reset() {
    ::reset();
    if(!present("water troll")) {
        new(MON_DIR+"water_troll")->move(this_object());
    }
}
