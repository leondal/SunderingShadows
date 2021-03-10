// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ankheg4");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^ORANGE%^an u%^WHITE%^n%^ORANGE%^f%^BOLD%^%^BLACK%^i%^RESET%^ni%^ORANGE%^s%^BOLD%^%^BLACK%^h%^RESET%^e%^ORANGE%^d t%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^n%^WHITE%^n%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^l%^WHITE%^");

    set_long("%^ORANGE%^Sloping sharply upward from the cavern behind you, leading into apparent %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^. Loose d%^WHITE%^i%^ORANGE%^rt and %^WHITE%^l%^BOLD%^o%^RESET%^%^ORANGE%"
	"^a%^WHITE%^m %^ORANGE%^still makes up most of the ground beneath, making travel difficult. The freshly-dug path stops short of what you think must be the surface, and doesn't appear to lead anywhere e"
	"lse.%^WHITE%^"
	);

    set_smell("default","
The smell of damp, loam, and a fresh dig permeates this space.");
    set_listen("default","You can hear things clicking and moving about, from the other side of the dirt walls");


    set_exits(([ 
		"north" : "/d/av_rooms/brandobaris/ankheg3",
	]));

}