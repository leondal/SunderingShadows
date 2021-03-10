// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_hall_east1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rk%^WHITE%^e%^BLACK%^ned H%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^llw%^WHITE%^a%^BLACK%^y%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in a darkened hallway of what must be a %^RESET%^%^MAGENTA%^c%^BLUE%^r%^MAGENTA%^ypt%^BOLD%^%^BLACK%^. The roof overhead is fractured with cracks and bits of stone drop ever"
	"y now and then. C%^WHITE%^o%^BLACK%^f%^WHITE%^f%^BLACK%^ins are tucked away in bricked openings that line the walls. A deep %^RESET%^%^MAGENTA%^gloom%^BOLD%^%^BLACK%^ permeates the claustrophobic pass"
	"ageways that seems more than meer %^BLUE%^darkness.%^RESET%^ "
	);

    set_smell("default","
%^BOLD%^%^BLACK%^A m%^YELLOW%^u%^BOLD%^%^BLACK%^sky scent of %^GREEN%^mold%^BOLD%^%^BLACK%^ and ancient st%^WHITE%^o%^BOLD%^%^BLACK%^ne pervades the room.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^The only sound is that of your own footsteps.%^RESET%^");


    set_exits(([ 
		"northeast" : "/d/av_rooms/myrkul/crypt_hall_east2",
		"west" : "/d/av_rooms/myrkul/crypt_clinic",
	]));

}