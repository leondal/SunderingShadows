// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("klauth_P6");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("shore");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Grasslands of Aramanth%^RESET%^");

    set_long("%^RESET%^You make your way up and away from the shoreline, leaving the foul smell of rotting %^GREEN%^seaweed %^RESET%^and other less identifiable things and start to trek through the %^ORANGE%^thick "
	"grass %^RESET%^of the upper banks.  To the southeast you can see the %^BLUE%^Sea %^RESET%^in all its glory and ahead to the northeast a %^CYAN%^river %^RESET%^winds its way down to an inlet.  Cutting "
	"its way between%^BOLD%^%^BLACK%^ mountains%^RESET%^.  High above you can see a %^ORANGE%^bridge %^RESET%^spanning this chasm, but it would require a lot of climbing to reach, you only hope that there "
	"is a way across the %^CYAN%^river %^RESET%^that can be crossed this far down the mountain.%^RESET%^"
	);

    set_smell("default","
The air is rank with the smell of rotten seaweed.");
    set_listen("default","You hear the sound of the ocean.");

}