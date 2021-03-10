// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("trial3");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("paved road");
    set_climate("mountain");

    set_short("%^RESET%^%^CYAN%^Ice cavern");

    set_long("%^RESET%^%^CYAN%^You are within a large cavern bored into a mountain of %^BOLD%^glacial ice%^RESET%^%^CYAN%^.  Natural light cannot penetrate the thick walls here, forcing you to rely on other means t"
	"o catch your bearings.  Beneath your feet crunches a layer of ice crystals.  The walls around you %^BOLD%^shimmer %^RESET%^%^CYAN%^like %^BOLD%^%^WHITE%^glass%^RESET%^%^CYAN%^.  The ceiling rises a bi"
	"t here, falling out of your vision.  The tunnel mouth leads back to the passage with the door.%^CYAN%^%^RESET%^"
	);

    set_smell("default","
%^BLUE%^It smells crisp and clean.%^RESET%^");
    set_listen("default","%^MAGENTA%^You hear your footsteps echo.%^RESET%^");


    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/trial1",
	]));

}