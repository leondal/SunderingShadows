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
	    set_name("foothills");
        set_terrain(ROCKY);
        set_travel(RUTTED_TRACK);
        set_property("indoors",0);
        set_property("light",3);
	    set_climate("temperate");
        set_short("%^BOLD%^%^YELLOW%^Rolling Foothills%^RESET%^");
        set_long( (: TO,"long" :) );
        set_smell("default","\n%^RESET%^%^ORANGE%^You smell the various plants in the area.%^RESET%^");
        set_listen("default","%^RESET%^%^CYAN%^You hear the sound of birds in the air periodically.%^RESET%^");
        set_items(([
        "mountains" : "%^RESET%^%^BLUE%^The mountains rise high into the air to the east, giving"+
		" a majestic view of the %^BOLD%^%^WHITE%^snow-capped %^RESET%^%^BLUE%^peaks.",
        "brush" : "%^RESET%^%^GREEN%^The brush is sparse and made up of a variety of short grasses and shrubs.",
        "keep" : "%^BOLD%^%^WHITE%^Off a distance to the east-southeast, you see large stone keep. Cresting over the"+
		" %^RESET%^%^BLUE%^mountain, %^BOLD%^%^WHITE%^and is likely the most prominant structure save the %^RESET%^%^BLUE%^"+
		" mountains %^BOLD%^%^WHITE%^to the east.",
        "forest" : "%^BOLD%^%^GREEN%^To the west tall trees rise up out of the grassland. The forests spread"+
		" for miles and miles and are quite majestic.",
		"grasslands"	: "%^RESET%^%^GREEN%^The grasslands span out off the foothills, encompassing all of"+
		" the area up until the massive forest. A small %^RESET%^%^CYAN%^hamlet %^RESET%^%^GREEN%^is located to"+
		" the west.",
		"hamlet" : "%^BOLD%^%^CYAN%^The hamlet is to the west, comprising of a few buildings that seem to be mostly"+
		" under construction.",
		]));
        set_exits(([
        "north" : ROOMS"foothills",
]));
}

string long(string str)
{
    return("%^RESET%^The rolling hills in this area extend down from the %^RESET%^%^BLUE%^mountains"+
		" %^RESET%^which rise to the east. The ground here has sporatic %^RESET%^%^GREEN%^brush%^RESET%^"+
		", however, very little vegetation. The foothills continue west, gradually sloping down"+
		" to the large %^BOLD%^%^GREEN%^grasslands%^RESET%^ and %^RESET%^%^GREEN%^forest%^RESET%^"+
		" to the west. To the east-southeast you see a %^BOLD%^%^WHITE%^keep %^RESET%^standing on"+
		" an outcropping of the mountain."
		);
}



