//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/11/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "You can smell danger as if it was a real thing.");
    set_listen("default", "A howl of a wolf cuts through the silence.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Darkwood Forest");
    set("long", "You are lost deep within clutches of Darkwood Forest.  "+
        "The ancient trees are unnaturally dense and you feel as if "+
        "they are watching your every move.  High above you, the tree "+
        "branches are locked in a twisted battle of survival effectivly "+
        "blotting out the sky and any light or warmth it provides.  You "+
        "hear a howl of a wolf echo through the forest which sends chills "+
        "up your spin.  A very small opening through the trees to the "+
        "west, southwest, and southeast are visible.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
    ]) );
    set_exits( ([
        "west": ROOM_DIR+"forest21",
        "southwest": ROOM_DIR+"forest25",
        "southeast": ROOM_DIR+"forest19",
    ]) );
}
