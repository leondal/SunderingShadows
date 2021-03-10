// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ankheg2");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^a cramped, %^RESET%^%^ORANGE%^l%^WHITE%^o%^BOLD%^%^BLACK%^a%^RESET%^m%^ORANGE%^y %^BOLD%^%^BLACK%^t%^RESET%^u%^BOLD%^%^BLACK%^n%^RESET%^n%^BOLD%^e%^BLACK%^l%^RESET%^");

    set_long("%^ORANGE%^The %^BOLD%^%^BLACK%^dark%^RESET%^%^ORANGE%^, %^WHITE%^l%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^m%^RESET%^y %^ORANGE%^tunnel continues on for a long stretch, and your sight li"
	"nes vanish into %^BOLD%^%^BLACK%^in%^RESET%^k%^BOLD%^%^BLACK%^y-b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k d%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^k%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^B"
	"LACK%^ss %^RESET%^%^ORANGE%^in either direction. The dirt passage looks even more unstable here, with the ceiling bulging heavily in and all but dripping soil onto the path below. Wading through the s"
	"%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ft, %^BOLD%^%^BLACK%^a%^RESET%^i%^ORANGE%^r%^BOLD%^%^BLACK%^y d%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^rt %^RESET%^%^ORANGE%^at your feet becomes more of a challenge "
	"here, and the walls look especially %^WHITE%^weak %^ORANGE%^in some places.%^WHITE%^"
	);

    set_smell("default","
The smell of damp, loam, and a fresh dig permeates this space.");
    set_listen("default","You can hear things clicking and moving about, from the other side of the dirt walls");

    
set_items(([ 
	({ "wall", "walls", "tunnel" }) : "%^ORANGE%^The already weakened walls look to be slightly weaker in places upon both the north and south walls.",
	({ "ground", "soil" }) : "%^ORANGE%^Almost coming up to waist height to an average human in places, the loose ground here makes any movement difficult.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/brandobaris/ankheg3",
		"east" : "/d/av_rooms/brandobaris/ankheg1",
	]));

}