//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/06/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

int found;

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
        "and any light and creating many dark shadows.  The forest floor "+
        "is matted with many rotting leaves, old brittle sticks and "+
        "contains a dark stream which flows from the east and leaves to "+
        "the west over some rotting logs.  The only way through this "+
        "cursed forest appears to be by following the stream.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
        "stream": "Its dark surface mirrors a twisted version of yourself.",
        "logs": "They are saturated with water and are rotted hollow.",
    ]) );
    set_exits( ([
        "west": ROOM_DIR+"forest10",
        "east": ROOM_DIR+"forest12",
    ]) );
}

void reset() {
    ::reset();
    found = 0;
}

void init() {
    ::init();
    add_action("search", "search");
}

int search(string str) {
    if(!str || str != "logs") {
        notify_fail("You find nothing interesting.\n");
        return 0;
    }
    if(found) {
        notify_fail("Something has been removed from the log already.\n");
        return 0;
    }
    message("my_action", "You have found a dagger hidden in its hollow!\n",
            this_player());
    message("other_action", (string)this_player()->query_cap_name()+
            "has found something in the log!",
            environment(this_player()), this_player());
    found = 1;
    new("/d/shadow/obj/weapon/dagger")->move(this_object());
    return 1;
}

