// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("test_2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("arctic");

    set_short("%^GREEN%^My Second Room%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Stone walls rise up on three sides of this empty chamber, while the fourth wall is made from a strange dark metal.  The smooth, slick surface of the metal makes a startling contrast t"
	"o the rougher stones that surround it.  Cool to the touch, its impossible to tell what it might be made of, though you can almost make out a faint pulsing energy coming from it.%^RESET%^"
	);

    set_smell("default","
There is a faint burning smell here, like heated metal.");
    set_listen("default","You can hear a very quiet hum coming from the strange metal wall.");

    set_search("ridge","%^BOLD%^%^BLUE%^You search along the wall and find a tiny ridge along the wall.  Searching it further, you think this might be the outline of an exit.  Only one you can't see.  Maybe you can try and %^RED%^enter%^BLUE%^ it to find out what is beyond!%^RESET%^");
    
set_items(([ 
	({ "[color=red]wall", "walls" }) : "%^BOLD%^%^BLACK%^There are three stone walls that look similar to the last room, while one of the walls is made of a smooth slab of metal.  Perhaps you could look at the %^RESET%^%^CYAN%^metal wall%^BOLD%^%^BLACK%^ or %^WHITE%^stone walls%^BLACK%^ to get a better look at either.%^RESET%^[/color]",
	({ "chair", "chairs" }) : "What are you looking at? There are no chairs in this room. It's empty, didn't you read the description? ",
	"metal wall" : "%^BOLD%^%^BLUE%^Smooth and solid, this wall is made from some type of metal you've never heard of before.  Touching it shows it to be smooth and warm, although there is a %^BLACK%^ridge%^BLUE%^ that mars the surface at one point.%^RESET%^",
	"stone wall" : "The stone walls look pretty standard.  Cut with rough edges and fit together, the blocks that make it up appear to be built by humans.",
	]));

    set_exits(([ 
		"west" : "/d/dagger/wiz_store2",
		"east" : "/d/av_rooms/lurue/test_1",
	]));



    set_invis_exits(({ "west" }));

}