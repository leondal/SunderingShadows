// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel7");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^MAGENTA%^In a deep tunnel%^RESET%^");

    set_long("tunnel7");

    set_smell("default","
%^ORANGE%^You smell age and dampness");
    set_listen("default","You hear scratching along the stone");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here depict images of war among many pyramids on a plain.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/tiamat/tunnel10",
		"west" : "/d/av_rooms/tiamat/tunnel6",
		"down" : "/d/av_rooms/tiamat/tunnel8",
		"east" : "/d/av_rooms/tiamat/tunnel9",
	]));

    set_door("grate","/d/av_rooms/tiamat/tunnel10","up","grate key","grate lock");
    add_lock("grate","grate key","grate lock","A keylock in the grate");
    set_locked("grate",1,"grate lock");
    lock_difficulty("grate",-10,"grate lock");
    set_open("grate",0);
    set_string("grate","knock","taps on the grate");
    set_string("grate","open","You unhinge the grate");
    set_string("grate","close","You re set the grate");
    set_door_description("grate","A heavy metal grate leading up with a lock on the east edge");
}