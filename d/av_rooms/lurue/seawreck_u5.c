// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_u5");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("deep water");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^Under the sea%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Swimming under the surface of the Saakrune Sea, visibility is reduced to a pale b%^BLUE%^l%^CYAN%^u%^GREEN%^e%^BLUE%^-%^GREEN%^g%^BLUE%^r%^CYAN%^e%^BOLD%^%^BLUE%^e%^RESET%^%^GREEN%^n "
	"%^CYAN%^shade of ever moving swirls.  Small fish dart about in %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^ve%^RESET%^r%^BOLD%^%^WHITE%^y %^RESET%^%^CYAN%^schools, while flakes of %^ORANGE%"
	"^coral %^CYAN%^drift in the pale light from the surface.  Nearby, the mountainous structure of a coral shelf can be seen drifting lower into the murky depths of the ocean. A part of the structure appe"
	"ars to be damaged here from where a large piece of the ship struck it.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell under the water.");
    set_listen("default","You can hear the sound of your air bubbling away.");

    set_search("crack","%^BOLD%^%^BLACK%^Gently you extend your hand and feel around the sharp edges of the coral.  After a bit of investigating, you discover that whatever this structure is, this crack leads to an open space and you might just be able to fit through, if you were careful when you %^RED%^enter%^BLACK%^.%^RESET%^");
    set_search("coral","%^BOLD%^%^BLACK%^Gently you extend your hand and feel around the sharp edges of the coral.  After a bit of investigating, you discover that whatever this structure is, this crack leads to an open space and you might just be able to fit through, if you were careful when you %^RED%^enter%^BLACK%^.%^RESET%^");
    
set_items(([ 
	({ "flakes", "schools", "fish" }) : "%^BOLD%^%^WHITE%^Colorful little %^BLUE%^f%^YELLOW%^i%^RESET%^%^BLUE%^s%^BOLD%^h %^WHITE%^dart about, catching up the bits of mater that float from the large coral covered structure nearby.  Their little forms weaving back and forth in tight schools.%^RESET%^",
	({ "structure", "coral" }) : "%^RESET%^%^ORANGE%^Coral and other bits of mater float about in the water here, making it a bit more murky then the deeper waters.  A coral covered structure looms nearby, likely the cause of this debris.  Here there is a bit of a %^WHITE%^crack %^ORANGE%^in the wall though, as though something large hit it and broke some of the coral away.%^RESET%^",
	"ship" : "%^BOLD%^%^BLACK%^The strange coral covered structure appears to have claimed at least one ship, as the wood and metal debris litter the vertical surface of the coral. %^RESET%^",
	"crack" : "%^BOLD%^%^BLACK%^The coral appears to have been broken away in this one spot.  Maybe you could %^BLUE%^search%^BLACK%^ around where its clear and figure out what's underneath.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/seawreck_u7",
		"north" : "/d/av_rooms/lurue/seawreck_u2",
		"east" : "/d/av_rooms/lurue/seawreck_u6",
		"enter" : "/d/av_rooms/lurue/seawreck_c1",
	]));



    set_invis_exits(({ "enter" }));

}