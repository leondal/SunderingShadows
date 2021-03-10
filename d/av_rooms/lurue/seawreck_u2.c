// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_u2");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("deep water");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^Under the sea%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Swimming under the surface of the Saakrune Sea, visibility is reduced to a pale b%^BLUE%^l%^CYAN%^u%^GREEN%^e%^BLUE%^-%^GREEN%^g%^BLUE%^r%^CYAN%^e%^BOLD%^%^BLUE%^e%^RESET%^%^GREEN%^n "
	"%^CYAN%^shade of ever moving swirls.  Small fish dart about in %^WHITE%^%^BOLD%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^ve%^RESET%^r%^BOLD%^%^WHITE%^y %^RESET%^%^CYAN%^schools, while flakes of %^ORANGE%"
	"^coral %^CYAN%^drift in the pale light from the surface.  Nearby, the mountainous structure of a %^ORANGE%^c%^MAGENTA%^o%^BLUE%^r%^ORANGE%^al s%^MAGENTA%^h%^BLUE%^e%^ORANGE%^lf %^CYAN%^can be seen dri"
	"fting lower into the murky depths of the ocean. Extending from part of the structure appears to be the remains of some part of a %^BOLD%^%^BLACK%^ship%^RESET%^%^CYAN%^, but it is too broken and corrod"
	"ed to tell.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell under the water.");
    set_listen("default","You can hear the sound of your air bubbling away.");

    
set_items(([ 
	({ "structure", "coral" }) : "%^RESET%^%^ORANGE%^Coral and other bits of mater float about in the water here, making it a bit more murky then the deeper waters.  A coral covered structure looms nearby, likely the cause of this debris.%^RESET%^",
	({ "flakes", "schools", "fish" }) : "%^BOLD%^%^WHITE%^Colorful little %^BLUE%^f%^YELLOW%^i%^RESET%^%^BLUE%^s%^BOLD%^h %^WHITE%^dart about, catching up the bits of mater that float from the large coral covered structure nearby.  Their little forms weaving back and forth in tight schools.%^RESET%^",
	"ship" : "%^BOLD%^%^BLACK%^The strange coral covered structure appears to have claimed at least one ship, as the wood and metal debris litter the vertical surface of the coral. %^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/seawreck_u6",
		"northeast" : "/d/av_rooms/lurue/seawreck_u1",
		"south" : "/d/av_rooms/lurue/seawreck_u5",
		"surface" : "/d/av_rooms/lurue/seawreck_s2",
	]));

}