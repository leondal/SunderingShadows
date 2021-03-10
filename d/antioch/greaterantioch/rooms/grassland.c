#include <std.h>
#include "../gantioch.h"

inherit ROOM;

void create()
{
        ::create();
	  set_name("grassland");
        set_property("indoors",1);
        set_property("light",2);
	  set_climate("temperate");

        set_short("%^RESET%^%^GREEN%^Lush Grasslands%^RESET%^");
        set_long(
@WORKROOM
%^RESET%^%^GREEN%^Lush Grasslands%^RESET%^
%^BOLD%^%^GREEN%^You are walking in a lush grassland. All about you are beautiful %^BOLD%^%^MAGENTA%^fl%^BOLD%^%^WHITE%^ow%^BOLD%^%^RED%^ers%^BOLD%^%^GREEN%^. Insects hop about and you see the occasional %^RESET%^%^ORANGE%^animal %^BOLD%^%^GREEN%^scurry about. To the northwest you see what looks to be a %^BOLD%^%^WHITE%^keep%^BOLD%^%^GREEN%^ in the distance. You see directly to the east a %^RESET%^%^ORANGE%^road%^BOLD%^%^GREEN%^ which continues into the distance. To the north you see the tall %^RESET%^%^GREEN%^trees %^RESET%^%^ORANGE%^of the %^BOLD%^%^GREEN%^King's Forest %^BOLD%^%^GREEN%^in the distance.%^RESET%^ 
WORKROOM
        );
        set_smell("default","%^RESET%^%^GREEN%^The smell of grass permeates the air.%^RESET%^");
        set_listen("default","%^RESET%^%^ORANGE%^You hear the sound of crickets and insects.%^RESET%^");
        set_items(([
        "grass" : "%^RESET%^%^GREEN%^The grass here stands almost a foot high"+
		" and is made of various kinds of %^BOLD%^%^GREEN%^plants%^RESET%^%^GREEN%^.",
        "flowers" : "%^RESET%^%^ORANGE%^The flowers here vary greatly from small %^BOLD%^%^YELLOW%^sunflowers"+
		" %^RESET%^%^ORANGE%^to %^BOLD%^%^RED%^tulips %^RESET%^%^ORANGE%^and give beautiful contrast to the area.",
        "keep" : "%^BOLD%^%^WHITE%^Off a distance to the north, you see large stone keep. Cresting over the."+
		"%^RESET%^%^GREEN%^forest %^BOLD%^%^WHITE%^,it is likely the most prominant structure save the %^RESET%^%^BLUE%^"+
		" mountains %^BOLD%^%^WHITE%^to the east.",
        "trees" : "%^BOLD%^%^GREEN%^To the north tall trees rise up out of the grassland areas. The forests spread"+
		" for miles and miles and are quite majestic.",
		"road"	: "%^RESET%^%^ORANGE%^The road goes into the distance and is made up of compact dirt."
		]));
        set_exits(([
        "north" : ROOMS"grassland",
]));
}




