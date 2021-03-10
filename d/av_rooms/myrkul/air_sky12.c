// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("air_sky12");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("barren");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Cloudswept Sky%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^Flying through the air about a hundred feet above the ground, %^WHITE%^clouds%^CYAN%^ pass by like great fluffy white elephants. Below you the %^RESET%^%^ORANGE%^ground%^BOLD%^%^CYAN%^"
	" seems to wizz past in a blur. You can make out %^GREEN%^trees%^CYAN%^ and %^RESET%^%^ORANGE%^farms%^BOLD%^%^CYAN%^ dotting the landscape. Birds glide languidly through the air, and it seems clear tha"
	"t this piece of sky is still within bow shot.%^RESET%^"
	);

    set_smell("default","
You smell the clean fresh air of the wind.");
    set_listen("default","The rushing of fast air whistles past you.");


    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/air_sky11",
	]));

}