// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("seawreck_s1");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("shallow water");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^The wide open sea%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Drifting on the vast open %^BLUE%^%^BOLD%^sea%^RESET%^%^CYAN%^, the rise and drop of each swell reminds you just how small a being you truly are.  The dark b%^BLUE%^l%^CYAN%^u%^GREEN%"
	"^e%^BOLD%^%^BLUE%^-%^RESET%^%^GREEN%^g%^BLUE%^r%^CYAN%^e%^BOLD%^%^BLUE%^e%^RESET%^%^GREEN%^n %^CYAN%^waters prevents you from seeing much more then your feet feebly kicking back and forth as you fight"
	" to stay afloat. Only a %^ORANGE%^coral %^CYAN%^covered structure to the west offers any point of reference out in this vast nothingness you find yourself in.%^RESET%^"
	);

    set_smell("default","
Salt spray tingles your nose.");
    set_listen("default","The constant roar of the ocean is all around you.");

    set_search("coral","%^RESET%^%^ORANGE%^You carefully chip away at the coral structure trying to divine what might be under it.  Small %^BLUE%^f%^YELLOW%^i%^BLUE%^s%^RESET%^%^BLUE%^h %^ORANGE%^ dart away from your attack upon their home, while plumes of crushed coral fill the water with a blinding dust.  For all your efforts, all you find is more coral.%^RESET%^");
    
set_items(([ 
	"coral" : "%^RESET%^%^ORANGE%^The coral appears to have built up over a very long time, leading you to think the structure is probably quite old.%^RESET%^",
	"structure" : "%^BOLD%^%^BLACK%^It's hard to tell what it is exactly, as covered in %^RESET%^%^ORANGE%^coral%^BOLD%^%^BLACK%^ as it is, but you think it might be part of an underwater mountain system.  Maybe there is a cave further down, though diving so close to the reef would probably be suicide. Maybe you should swim further out.%^RESET%^",
	"water" : "%^BOLD%^%^BLUE%^The water stretches all around you, filing your vision with its emptiness.  Maybe you should think about returning to your boat before you're swept too far away.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/seawreck_s4",
		"west" : "/d/shadow/virtual/sea/fall.dock",
	]));

}