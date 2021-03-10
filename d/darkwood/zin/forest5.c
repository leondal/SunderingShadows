//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/11/95

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
    set("long", "You have entered into a dark clearing.  The twisted "+
        "trees and dark branches of Darkwood Forest still form a thick "+
        "mass far above you cloaking the entire sky.  Thrown about the "+
        "clearing are many discared bones and mutilated corpses.  "+
        "Dominating center of the clearing is a huge fist carved from "+
        "a dull onyx stone unknown to you.  The dark trees are packed "+
        "very close together making passage impossible except to the "+
        "west.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
        "bones": "They appear half eaten.",
        "corpses": "They are half decayed.",
        "fist": "You notice it is actually hollow.  The north side of "+
                "it is open and may be entered if you dare!",
    ]) );
    set_exits( ([
        "west": ROOM_DIR+"forest4",
    ]) );
}

void init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {
    if(!str && str != "fist") {
        notify_fail("Enter what?\n");
        return 0;
    }
    message("my_action", "You step into the darkness of the fist.",
            this_player());
    message("other_action", (string)this_player()->query_cap_name()+
            "steps into the darkness of the fist.",
            environment(this_player()), this_player());
    this_player()->move_player(ROOM_DIR+"temple1");
    return 1;
}
