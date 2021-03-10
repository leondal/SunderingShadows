#include <std.h>
#include "../gantioch.h"

inherit CROOM;

void make_creatures();
void find_stuff();
void searchroom();

int searched;

void create()
{
        ::create();
	    set_name("road");
        set_property("indoors",0);
        set_property("light",2);
	    set_climate("temperate");
	    set_travel(RUTTED_TRACK);
	    set_terrain(ROCKY);
        set_short("%^RESET%^%^ORANGE%^A road through kings forest%^RESET%^");
        set_long( (: TO,"long" :) );
        set_smell("default","\n\n%^RESET%^%^GREEN%^The smell of grass and %^RESET%^%^ORANGE%^dirt %^RESET%^%^GREEN%^permeates the air.%^RESET%^");
        set_listen("default","%^RESET%^%^ORANGE%^You hear the sound of crickets and insects.%^RESET%^");
        set_items(([
        "keep" : "%^BOLD%^%^WHITE%^Off a distance, you see a large stone keep. Cresting over the"+
		" %^RESET%^%^GREEN%^foothills%^BOLD%^%^WHITE%^, it is likely the most prominant structure save the%^RESET%^%^BLUE%^"+
		" mountains %^BOLD%^%^WHITE%^to the east.",
		"plants" : "%^RESET%^%^GREEN%^The grass here stands almost a foot high near the road and various flowers and shrubs also line the path.",
		"mountains" : "%^BOLD%^%^BLUE%^The majestic mountains rise high into the sky, covered with %^BOLD%^%^WHITE%^snow %^BOLD%^%^BLUE%^and incredibly beautiful.",
    ]) );
        set_exits(([
        "north" : ROOMS"grassland",
]));
}

string long(string str)
{
    return("%^RESET%^%^ORANGE%^The wide dirt road you are on is just over fifteen feet wide and seems well maintained."+
           " %^BOLD%^%^GREEN%^Plants %^RESET%^%^ORANGE%^grow alongside the road.");
}




