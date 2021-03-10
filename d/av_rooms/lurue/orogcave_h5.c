// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_h5");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The tunnel curves to the southwest and continues to rise at an ever increasing angle, while to the east it curves around and begins to slope downward toward the main entrance.  Wide e"
	"nough to allow several armored Orog warriors to pass through, the walls look smooth and unmarred here.  A few %^RESET%^%^BLUE%^alcoves %^BOLD%^%^BLACK%^can be seen toward the north end, residential qu"
	"arters for some of the Orogs.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"north" : "/d/av_rooms/lurue/orogcave_r3",
		"east" : "/d/av_rooms/lurue/orogcave_h4",
		"southwest" : "/d/av_rooms/lurue/orogcave_h6",
	]));

}