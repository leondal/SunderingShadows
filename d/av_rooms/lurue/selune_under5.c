// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("selune_under5");
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
		"southeast" : "/d/av_rooms/lurue/selune_under4",
		"northeast" : "/d/av_rooms/lurue/selune_under5",
		"west" : "/d/av_rooms/lurue/selune_under5",
		"south" : "/d/av_rooms/lurue/selune_under5",
		"north" : "/d/av_rooms/lurue/selune_under5",
		"east" : "/d/av_rooms/lurue/selune_under5",
		"northwest" : "/d/av_rooms/lurue/selune_under5",
		"southwest" : "/d/av_rooms/lurue/selune_under6",
	]));

}