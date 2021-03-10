// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ankheg3");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^an e%^RESET%^%^ORANGE%^r%^WHITE%^od%^ORANGE%^e%^BOLD%^%^BLACK%^d c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^v%^RESET%^e%^ORANGE%^r%^BOLD%^%^BLACK%^n%^RESET%^");

    set_long("%^ORANGE%^The cramped tunnels open up here as the loamy soil gives way to %^WHITE%^solid rock%^ORANGE%^, looking to have been freshly %^WHITE%^eroded %^ORANGE%^away. Small %^BOLD%^%^GREEN%^p%^ORANGE%^"
	"u%^GREEN%^d%^ORANGE%^d%^GREEN%^l%^ORANGE%^e%^GREEN%^s %^RESET%^%^ORANGE%^of %^BOLD%^%^GREEN%^greenish acid %^RESET%^%^ORANGE%^fill some of the floor's crevices, eating into the rock even as it %^BOLD%"
	"^%^GREEN%^b%^ORANGE%^u%^GREEN%^b%^ORANGE%^b%^GREEN%^l%^ORANGE%^e%^GREEN%^s %^RESET%^%^ORANGE%^and %^WHITE%^dissipates%^ORANGE%^. Three tunnels connect to this chamber - the unstable-looking tunnel lea"
	"ding back to the east, and another to the south which seems to slope upwards sharply. To the north, a tunnel composed mostly of %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ck %^RESET%^%^ORANGE%^leads"
	" deeper into this hidden cavern, and the noises about you seem to echo even more loudly from its depths...%^WHITE%^"
	);

    set_smell("default","
The smell of damp, loam, and a fresh dig permeates this space.");
    set_listen("default","You can hear things clicking and moving about, from the other side of the dirt walls");


    set_exits(([ 
		"north" : "/d/av_rooms/brandobaris/ankheg5",
		"south" : "/d/av_rooms/brandobaris/ankheg4",
		"east" : "/d/av_rooms/brandobaris/ankheg2",
	]));

}