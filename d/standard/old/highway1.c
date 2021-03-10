#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("no castle", 1);
    set("short", "A dirt highway");
    set("long",
	"You are on a dirt highway outside the adventuring village "
	"of Praxis.  The Daroq Mountains loom ominously in the west.");
    set_items(
	(["highway" : "A highway linking Praxis to the western lands "
	    "of Nightmare.",
	  "village" : "A tiny adventuring village. They have many "
	    "services there.",
	  "mountains" : "The Daroq Mountains, home to many vile creatures."
	]) );
    set_exits( 
	      (["west" : "/d/standard/highway2",
		"east" : "/d/standard/w_boc_la3"]) );
}

