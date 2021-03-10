// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("Throne_of_Blood");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("barren");
    set_travel("rubble");
    set_climate("desert");

    set_short("%^BOLD%^%^BLACK%^Before a %^BOLD%^%^WHITE%^sk%^RESET%^e%^BOLD%^%^WHITE%^le%^RESET%^t%^BOLD%^%^WHITE%^al %^BLACK%^bridge%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You have come across a dark and ominous castle in this barren wasteland. Before you stands a bridge made completely from %^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^n%^RESET%^e%^BOLD%^%^WHIT"
	"E%^s%^BLACK%^. This bridge crosses high above a mote of a thick and dark %^RESET%^%^RED%^red %^BOLD%^%^BLACK%^substance. Across the moat you can see seamless obs%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^d"
	"%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^an walls  towering over one-hundred stories into the sky above you. Carved into these walls are numerous grotesque and devilish faces. Each face has a seemingly i"
	"nfinite amount of the dark red liquid pouring from it's mouth, endlessly filling the moat before you. The only visible entrance into the impenetrable walls of this castle shows itself in the form of a"
	"n equally tall set of doors, made from the same obisidian as the walls themselves. Red, glowing runes have been carved into these doors and put off an eerie light.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^BLACK%^You smell the sharply metallic scent of %^RED%^blood%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^The tortured screams of countless %^WHITE%^souls %^BLACK%^can be heard%^RESET%^");


    set_exits(([ 
		"out" : "/d/dagger/avalounge",
		"bridge" : "/d/av_rooms/bhaal/Throne_of_Blood2",
	]));

}