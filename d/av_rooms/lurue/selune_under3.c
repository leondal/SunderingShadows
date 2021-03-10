// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("selune_under3");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Under the Temple of Selune");

    set_long("%^BOLD%^%^WHITE%^The hallway opens to a wide chamber wherein a set of silver plated metal doors stands blocking further entrance into the passage.  Carved from the same stone as the rest of the hallwa"
	"y, this chamber does not feature paintings, or any other type of elaboration beyond the pair of statues and the mirror bright doors.%^RESET%^"
	);

    set_smell("default","You detect the faintest hint of night-blooming jasmine.");
    set_listen("default","The corridor is silent but for the sounds you make.");


    set_exits(([ 
		"west" : "/d/av_rooms/lurue/selune_under2",
		"east" : "/d/av_rooms/lurue/selune_under4",
	]));

    set_door("double doors","/d/av_rooms/lurue/selune_under4","east","moonstone rod","silver door lock");
    add_lock("double doors","moonstone rod","silver door lock","%^BOLD%^%^BLACK%^This tiny hole in the middle of the two mirrored doors seems far too small but for the most slender of objects to fit within it.%^RESET%^");
    set_locked("double doors",1,"silver door lock");
    lock_difficulty("double doors",-75,"silver door lock");
    set_open("double doors",0);
    set_string("double doors","knock","knocks on the");
    set_string("double doors","open","The doors open silently.");
    set_string("double doors","close","The doors close silently");
    set_door_description("double doors","%^BOLD%^%^WHITE%^Made of polished silver plates, these doors reflect back a perfect likeness of the room around them, including yourself.  A thin seam can be seen where the two doors meet, and about half way down, there is a small hole where something very slender could be inserted.%^RESET%^");
}