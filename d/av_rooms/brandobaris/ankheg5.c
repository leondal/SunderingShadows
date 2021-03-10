// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ankheg5");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^a l%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^e, e%^RESET%^x%^ORANGE%^p%^WHITE%^a%^ORANGE%^n%^WHITE%^s%^BOLD%^i%^RESET%^v%^BOLD%^%^BLACK%^e c%^WHITE%^a%^RESET%^v%^ORANGE%^e%^WHITE%^r%^BOLD%^%^BLACK%^n%^RESET%^");

    set_long("%^ORANGE%^You have entered a large, %^WHITE%^r%^BOLD%^%^BLACK%^o%^WHITE%^c%^RESET%^%^ORANGE%^k%^WHITE%^y c%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^v%^BOLD%^%^WHITE%^e%^BLACK%^r%^RESET%^n%^ORANGE%^, this o"
	"ne looking to have been formed naturally. The ground beneath is solid %^WHITE%^rock%^ORANGE%^, though its topmost layer seems to have been freshly eroded away by the small pools of %^BOLD%^%^GREEN%^b%"
	"^ORANGE%^u%^GREEN%^b%^ORANGE%^b%^WHITE%^l%^GREEN%^i%^ORANGE%^n%^GREEN%^g g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^i%^WHITE%^s%^BOLD%^%^GREEN%^h a%^WHITE%^c%^ORANGE%^i"
	"%^GREEN%^d %^RESET%^%^ORANGE%^that fill some of the floor's crevices. Near to the back of the cavern lies a heap of loose %^BOLD%^%^WHITE%^rocks %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^debris %^RESET%"
	"^%^ORANGE%^that seem to have been knocked loose from the cavern ceiling - it seems this place is not particularly stable. Found throughout the room are a dozens of giant p%^BOLD%^%^BLACK%^i%^RESET%^%^"
	"ORANGE%^l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s of packed d%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^, some of them reaching fifteen feet tall.%^WHITE%^"
	);

    set_smell("default","
The smell of damp, loam, and a fresh dig permeates this space.");
    set_listen("default","You can hear things clicking and moving about, from the other side of the dirt walls");

    set_search("debris","%^ORANGE%^A small tunnel leads out of this chamber to the %^WHITE%^northeast%^ORANGE%^.%^WHITE%^");
    set_search("rock","%^ORANGE%^A small tunnel leads out of this chamber to the %^WHITE%^northeast%^ORANGE%^.%^WHITE%^");
    set_search("rocks","%^ORANGE%^A small tunnel leads out of this chamber to the %^WHITE%^northeast%^ORANGE%^.%^WHITE%^");
    
set_items(([ 
	({ "rock", "rocks", "debris" }) : "%^BOLD%^This large heap of %^RESET%^stone %^BOLD%^looks to have fallen from the cavern ceiling some time ago, and now lays discarded near to the back of the area. Nothing about it strikes you as particularly special, but it does seem just large enough to hide something...%^RESET%^",
	({ "dirt", "pile", "piles" }) : "%^ORANGE%^Though their purpose is not immediately apparent, each of them bears several large %^BOLD%^%^BLACK%^holes%^RESET%^%^ORANGE%^, and the pungent stench of %^GREEN%^a%^WHITE%^c%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^d %^ORANGE%^seeps out from them.%^WHITE%^",
	"ground" : "%^BOLD%^%^BLACK%^The ground is solid stone and surprisingly smooth, %^RESET%^eroded %^BOLD%^%^BLACK%^away by the strange %^GREEN%^acid%^BLACK%^.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/brandobaris/ankheg6",
		"south" : "/d/av_rooms/brandobaris/ankheg3",
	]));



    set_invis_exits(({ "northeast" }));

}