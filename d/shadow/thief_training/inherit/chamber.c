// Chernobog (10/27/20)
// Chamber Inherit for the Thief Tutorial Area

#include <std.h>
#include "../defs.h"
inherit CVAULT;

void create(){
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_climate("temperate");
	set_name("The Thief Tutorial Chambers");
	set_short("%^BOLD%^%^BLACK%^A rough-hewn stone chamber%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^What was once a natural cavern has been expanded into something serviceable for the guild. The %^RESET%^floor %^BOLD%^%^BLACK%^is a bit uneven and damp, and a %^RESET%^%^CYAN%^c%^BOLD%^h%^RESET%^%^CYAN%^i%^BOLD%^l%^RESET%^%^CYAN%^l %^BOLD%^%^BLACK%^permeates the chamber. Soft, %^RESET%^%^ORANGE%^f%^BOLD%^l%^WHITE%^i%^RESET%^%^ORANGE%^c%^BOLD%^k%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^r%^ORANGE%^i%^RESET%^%^ORANGE%^n%^BOLD%^g %^RESET%^%^ORANGE%^l%^BOLD%^i%^WHITE%^g%^ORANGE%^h%^RESET%^%^ORANGE%^ts %^BOLD%^%^BLACK%^in the walls offer some minor illumination.%^RESET%^");
	set_smell("default","It smells of mold and mildew.");
	set_listen("default","You hear the occasional drip of water hitting the stone floor.");
	set_items(([
		({"wall","walls"}) : "%^BOLD%^%^BLACK%^These are %^RESET%^stone walls %^BOLD%^%^BLACK%^that have been roughly cut out of the natural cavern.%^RESET%^",
		"floor" : "%^BOLD%^%^BLACK%^Uneven %^RESET%^slabs %^BOLD%^%^BLACK%^of raw %^RESET%^stone %^BOLD%^%^BLACK%^comprise the flooring here. They're a bit %^RESET%^%^CYAN%^slick %^BOLD%^%^BLACK%^with moisture.%^RESET%^",
		"lights" : "%^BOLD%^%^BLACK%^On closer inspection, the lights are %^RESET%^%^ORANGE%^d%^BOLD%^i%^RESET%^%^ORANGE%^m %^BOLD%^g%^RESET%^%^ORANGE%^l%^BOLD%^o%^WHITE%^w%^ORANGE%^s%^RESET%^%^ORANGE%^to%^BOLD%^%^WHITE%^n%^ORANGE%^e%^RESET%^%^ORANGE%^s %^BOLD%^%^BLACK%^tucked in a few crevices and on a couple shallow ledges.%^RESET%^",
		]));
}

