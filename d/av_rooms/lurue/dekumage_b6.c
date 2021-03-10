// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b6");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("a basement room");

    set_long("Stone walls create a small room here filled with old boxes and crates.  Wooden planks have been lain across the floor to keep the supplies off the floor and presumably dry, but the heavy moisture in t"
	"he room from where the water has seeped through the stones, has created patches of mildew upon several of the items.  This makes for little in the way of useful, salvageable items.  "
	);

    set_smell("default","
The pungent smell of mildew fills the room.");
    set_listen("default","All is silent but for your footfalls.");

    set_search("crates","%^GREEN%^You search about in the boxes and crates, but all you find is a lot of mildew and some old clothing.%^RESET%^");
    set_search("boxes","%^GREEN%^You search about in the boxes and crates, but all you find is a lot of mildew and some old clothing.%^RESET%^");
    
set_items(([ 
	({ "planks", "plank" }) : "The wooden planks were probably a good idea, but a lack of care for the goods in this room has made them all but useless.  Mold has begun growing on the surface of most crates and boxes.",
	({ "crates", "boxes", "box", "crate" }) : "The boxes and crates look old, as though they have been here for a very long time.  Based on the encroaching mold paterns, its likely they haven't been moved recently.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/dekumage_b3",
	]));

    set_door("south door","/d/av_rooms/lurue/dekumage_b3","north");
    set_open("south door",0);
    set_string("south door","knock","knocks on the");
    set_string("south door","open","The door creeks open.");
    set_string("south door","close","The door creeks closed.");
    set_door_description("south door","An old wooden door warped and swollen with moisture.");
}