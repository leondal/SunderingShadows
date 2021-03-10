//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/06/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "Something really smells bad here.");
    set_listen("default", "The gurgling stream dominates the area.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Darkwood Forest");
    set("long", "You are lost deep within clutches of Darkwood Forest.  "+
        "The ancient trees are unnaturally dense and you feel as if "+
        "they are watching your every move.  High above you, the tree "+
        "branches are locked in a twisted battle of survival effectivly "+
        "blotting out the sky and any light or warmth it provides.  A "+
        "narrow stream of cold dark water rushes by you from the "+
        "northeast and dissapears into the ground with a choking gurgle "+
        "sound.  You notice a pile of leaves near one of the twisted "+
        "trees.  A very small opening through the trees to the northwest "+
        "is visible and you may also follow the stream to the northeast.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
        "stream": "Its surface reflects a twisted version of yourself.",
        "pile": "It is covering a hole which is just large enough to enter.",
        "hole": "It is very dark, and smells very bad.",
    ]) );
    set_exits( ([
        "northwest": ROOM_DIR+"forest8",
        "northeast": ROOM_DIR+"forest10",
    ]) );
}

void init() {
    ::init();
    add_action("enter", "enter");
}

int enter (string str) {
    if(!str && str != "hole") {
        notify_fail("Enter what?\n");
        return 0;
    }
    message("my_action", "You take a deep breath and enter the hole.",
            this_player());
    message("other_action", (string)this_player()->query_cap_name()+
            "takes a deep breath and enters the hole.",
            environment(this_player()), this_player());
    this_player()->move_player(ROOM_DIR+"wolf_den");
    return 1;
}

