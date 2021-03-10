// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_h6");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The tunnel continues upward further into the mountain, curving in a zigzag as the incline becomes more pronounced.  Here, the smoothed walls of the hallway have been decorated with %^"
	"RESET%^%^MAGENTA%^elaborate paintings %^BOLD%^%^BLACK%^of battles and heroics.  Pieces of %^RESET%^%^CYAN%^metal %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^gems %^BOLD%^%^BLACK%^have been used to highli"
	"ght the artwork and add a richness of detail.  An %^RESET%^%^BLUE%^alcove %^BOLD%^%^BLACK%^extends to the east while the corridor slopes to the northeast and curves upward toward the north and more al"
	"coves.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/orogcave_h5",
		"north" : "/d/av_rooms/lurue/orogcave_h7",
		"east" : "/d/av_rooms/lurue/orogcave_b2",
	]));

}