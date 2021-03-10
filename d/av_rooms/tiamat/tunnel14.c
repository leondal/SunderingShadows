// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel14");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^MAGENTA%^Under the City");

    set_long("tunnel14");

    set_smell("default","
%^ORANGE%^You smell dampness");
    set_listen("default","%^GREEN%^You hear the distant drip of water");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here depict figures that appear to be gods in the forms of animals: A hawk, lion, serpent, and others among them.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/tiamat/tunnel15",
		"west" : "/d/av_rooms/tiamat/tunnel13",
		"down" : "/d/av_rooms/tiamat/tunnel16",
		"east" : "/d/av_rooms/tiamat/tunnel17",
	]));

}