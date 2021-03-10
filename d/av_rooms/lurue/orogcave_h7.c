// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_h7");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The tunnel continues upward, curving sharply toward the southwest and ascending into a narrowed stairwell.  To the south the corridor slopes downward back toward the entrance, while s"
	"everal %^RESET%^%^BLUE%^alcoves %^BOLD%^%^BLACK%^extend into the north end of the room.  Here, the smoothed walls of the hallway have been decorated with %^RESET%^%^MAGENTA%^elaborate paintings %^BOLD"
	"%^%^BLACK%^of battles and heroics.  Pieces of %^RESET%^%^CYAN%^metal %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^gems %^BOLD%^%^BLACK%^have been used to highlight the artwork and add a richness of detail"
	".%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"west" : "/d/av_rooms/lurue/orogcave_r1",
		"north" : "/d/av_rooms/lurue/orogcave_r2",
		"south" : "/d/av_rooms/lurue/orogcave_h6",
		"southwest" : "/d/av_rooms/lurue/orogcave_h8",
	]));

}