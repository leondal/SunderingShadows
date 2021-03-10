#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "The east end of Praxis");
    set("long",
	"You are at the eastern limits of the village Praxis. "
	 "Boc La, the main road running through the town, "
	"meets a path out into the wilderness heading east. "
	"East Road leads north from here to the Praxis Cemetary.");
    set_exits( 
	      (["west" : "/d/standard/e_boc_la2",
		"east" : "/d/standard/wild1",
		"north" : "/d/standard/east_road1",
		"south" : "/d/milieu/room/stair"]) );
    set_items(
	(["road" : "It leads west toward the village center.",
	  "village" : "Praxis is a small adventuring community "
	    "of the Nightmare reality.",
	  "wilderness" : "Stories tell of bandits and rogues out "
	    "in the wilderness."]) );
}

