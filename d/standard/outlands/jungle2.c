#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("no castle", 1);
    set("short", "The jungle");
    set("long",
	"You are on a tiny path through the deep jungle south of the "
        "outlaw town of Outland.  It is really hard to tell "
	"which ways you can go, and which ways you can't. ");
      set_listen("default", "The sounds of wild jungle animals "
		 "come at you from all directions.");
      set_items(
        (["path" : "It is barely that.",
	  "jungle" : "The colours of all the life blur before your eyes.",
	  "trees" : "Huge tropical trees forming a humid organic cover.",
	  "plants" : "The lush vegetation is growing everywhere.",
	  "tree" : "It's huge!",
	  "plants" : "It is sooooo %^GREEN%^%^BOLD%^green.%^RESET%^",
	  "colours" : "They are really beautiful.",
	  "animals" : "You cannot see them since they are so well "
	    "camouflaged.",
	  "vegetation" : "Plants and trees."]) );
    set_exits( 
	      (["north" : "/d/standard/outlands/jungle1",
		"east" : "/d/standard/outlands/cover3",
		"west" : "/d/standard/outlands/cover4",
		"south"	: "/d/standard/outlands/cover5"]) );
    set_invis_exits( ({ "east", "west", "south" }) );
    set_search("default", "You think you notice a way to move east , west, and south.");
    set_search("jungle", "You think you notice a way to move both to the east and the west.");
    set_search("trees", "You think you see a way to get through them east.");
    set_search("plants", "You think you see a way through them west.");
}

