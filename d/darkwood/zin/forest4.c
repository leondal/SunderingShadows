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
    set_listen("default", "You hear some grunting from the east.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Darkwood Forest");
    set("long", "You are lost deep within clutches of Darkwood Forest.  "+
        "The ancient trees are unnaturally dense which makes passage "+
        "very slow.  High above you, the tree branches are locked in "+
        "a twisted battle of survival effectivly blotting out the sky "+
        "and any light or warmth it provides.  You feel the presence of "+
        "evil and chaos concield in the many dark shadows cast all about "+
        "forest.  You occasionaly hear a deep grunt echo from somewhere "+
        "close.  The forest floor is matted with many rotting leaves "+
        "and old brittle sticks.  There appears to be three passable "+
        "gaps through the maze of trees to the north, south and west.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "You notice a passage hidden leading east.",
        "floor": "You notice a small trail leading east.",
        "trail":  "Something with big feet has walked through here.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
    ]) );
    set_exits( ([
        "north": ROOM_DIR+"forest3",
        "south": ROOM_DIR+"forest6",
        "west": ROOM_DIR+"forest4b",
        "east": ROOM_DIR+"forest5",
    ]) );
    set_invis_exits( ({"east"}) );
}
