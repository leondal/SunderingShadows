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
    set_listen("default", "The wind whistles slowly through the trees.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Darkwood Forest");
    set("long", "This appears to be the location of a crude camp "+
        "located deep within the heart of Darkwood Forest.  A very "+
        "small fire burn in the middle of the small break in the "+
        "trees.  There are a few sleeping furs around the fire.  High "+
        "above you, the tree branches are locked in a twisted battle "+
        "of survival effectivly blotting out the sky.  Many shadows "+
        "are created by the flickering light of the fire.  The forest "+
        "floor is matted with many rotting leaves and old brittle "+
        "sticks.  There appears to be a few passable gaps through the "+
        "trees to the south, west, and northwest.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
        "fire": "It crackles while the flames flicker about.",
        "furs": "They are scattered about the fire.",
    ]) );
    set_exits( ([
        "south": ROOM_DIR+"forest16",
        "west": ROOM_DIR+"forest29",
        "northwest": ROOM_DIR+"forest18",
    ]) );
}
