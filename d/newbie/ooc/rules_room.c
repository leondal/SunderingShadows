#include <std.h>

inherit ROOM;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("no teleport",1);
        set_property("light",2);
        set_property("no sticks",1);
	set_property("ooc room", 1);
        set_short("%^BOLD%^Room of rules");
        set_long(
"You're expected to obey rules of the game. 

To read them, please type %^BOLD%^<help rules>%^RESET%^.

We appreciate those who not only comply but also help to educate end encourage others to follow them.
"
        );
        set_exits(([
        "out" : "/d/newbie/ooc/hub_room2",
        ]));
}

