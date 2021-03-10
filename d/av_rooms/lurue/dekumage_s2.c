// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_s2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("dirt road");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A wooden stall%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^In the best repair, this stall looks to have received a bit of tending recently.  The %^BOLD%^%^BLACK%^warped boards %^RESET%^%^ORANGE%^have fresh nails and have been smoothed to re"
	"move any sign of splinter.  %^YELLOW%^Dried para grass %^RESET%^%^ORANGE%^lines this stalls floor and wide buckets of %^RESET%^food %^ORANGE%^and %^BLUE%^water %^ORANGE%^are attached under a window th"
	"at looks out into the swamp beyond.  Clearly the fierce looking stallion that resides here is better treated then the other animals.%^RESET%^"
	);

    set_smell("default","
You can smell the musk of horse flesh and fresh ground cover.");
    set_listen("default","An occasional whinny breaks the insect's drone.");

    set_search("grass","%^YELLOW%^Ewww, do you really want to know what you just put your hand into?%^RESET%^");
    set_search("para grass","%^YELLOW%^Ewww, do you really want to know what you just put your hand into?%^RESET%^");

    set_exits(([ 
		"east" : "/d/av_rooms/lurue/dekumage_s1",
	]));

}