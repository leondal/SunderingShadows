// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_a2");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^A glowing %^RESET%^%^RED%^red light %^BOLD%^%^BLACK%^illuminates this part of the immense cavern.  Sectioned off behind a wooden wall structure, this area is designed as a forge and a"
	"rmory.  A font of flowing %^RESET%^%^RED%^magma %^BOLD%^%^BLACK%^constantly bubbles in one corner, leaking the faint reddish light and filling the area with sulfuric heat.  Several large %^RESET%^%^BL"
	"UE%^anvils %^BOLD%^%^BLACK%^have been staged around this font, ready to serve the Orog metalsmiths in their work.  Nearby, just to the north, the results of their labor can be seen in the ornately des"
	"igned suits of armor and weapons that are stored there.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"west" : "/d/av_rooms/lurue/orogcave_a1",
		"south" : "/d/av_rooms/lurue/orogcave_h1",
	]));

}