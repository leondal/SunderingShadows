// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("selune_under6");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Chamber of Relics%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The walls here are covered in the same sheets of pressed silver that cover the doors, making this room mirror bright and disconcerting.  The reflections of thousand and thousands of r"
	"ooms just like this one blind you and leave you disoriented.%^RESET%^"
	);

    set_smell("default","You detect the faintest hint of night-blooming jasmine.");
    set_listen("default","The corridor is silent but for the sounds you make.");


    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/selune_under5",
		"northeast" : "/d/av_rooms/lurue/selune_under5",
		"south" : "/d/av_rooms/lurue/selune_under5",
		"west" : "/d/av_rooms/lurue/selune_under7",
		"north" : "/d/av_rooms/lurue/selune_under5",
		"east" : "/d/av_rooms/lurue/selune_under5",
		"southwest" : "/d/av_rooms/lurue/selune_under5",
		"northwest" : "/d/av_rooms/lurue/selune_under5",
	]));

    set_door("double doors","/d/av_rooms/lurue/selune_under7","west","moonstone rod","silver door lock");
    add_lock("double doors","moonstone rod","silver door lock","%^BOLD%^%^BLACK%^This tiny hole in the middle of the two mirrored doors seems far too small but for the most slender of objects to fit within it.%^RESET%^");
    set_locked("double doors",1,"silver door lock");
    lock_difficulty("double doors",-75,"silver door lock");
    set_open("double doors",0);
    set_string("double doors","knock","knocks on the");
    set_string("double doors","open","The door opens silently.");
    set_string("double doors","close","The door closes silently.");
    set_door_description("double doors","%^BOLD%^%^WHITE%^Made of polished silver plates, these doors reflect back a perfect likeness of the room around them, including yourself.  A thin seam can be seen where the two doors meet, and about half way down, there is a small hole where something very slender could be inserted.%^RESET%^");
}