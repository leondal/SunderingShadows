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
    set_listen("default", "The river bubbles by.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Darkwood Forest");
    set("long", "You are lost deep within clutches of Darkwood Forest.  "+
        "The ancient trees are unnaturally dense which makes passage "+
        "very slow.  High above you, the tree branches are locked in "+
        "a twisted battle of survival effectivly blotting out the sky "+
        "and any light and creating many dark shadows.  Through thin "+
        "slits between the twisted trees you make out a huge tower "+
        "to the east which is created from marble of the blackest "+
        "nature.  But the trees stand as a living wall preventing "+
        "you from venturing nearer.  A dark stream flows by you from "+
        "the southeast and leaves to the west.  The only way to "+
        "continue appears to be by following the stream.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
        "stream": "Its dark surface mirrors a twisted version of yourself.",
        "tower": "It is very beautiful, yet your bones ache from the evil "+
                 "which radiates from it.  There appears to be no way to "+
                 "reach it from here.",
    ]) );
    set_exits( ([
        "west": ROOM_DIR+"forest11",
        "southeast": ROOM_DIR+"forest13",
    ]) );
}
