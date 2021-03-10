// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_d5");
    set_property("indoors",0);
    set_property("light",-3);
    set_property("no teleport",1);
    set_terrain("deep water");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^RESET%^%^BLUE%^A deep underwater abyss%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^The deep waters of the ocean swirl around you in an %^BLACK%^inky blackness%^BLUE%^ that makes it near impossible to see.  Long gone are the faint rays of light cast by the moon and su"
	"n into the surface waters, all that is left is the cheerless %^RESET%^%^BLUE%^abyss %^BOLD%^of the deep waters.  The occasional flicker of %^RESET%^%^BLUE%^p%^GREEN%^h%^CYAN%^os%^BLUE%^ph%^CYAN%^o%^GR"
	"EEN%^r%^BLUE%^es%^CYAN%^ce%^GREEN%^nt %^BLUE%^li%^CYAN%^g%^GREEN%^h%^BLUE%^t %^BOLD%^catches your attention, but as soon as you turn toward it, it flits away, born away by the fish whose body has adap"
	"ted to this dark realm.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The sound of bubbles escaping from your mouth are the only thing you hear.");

    
set_items(([ 
	({ "darkness", "dark" }) : "%^BOLD%^%^BLACK%^Even in this darkness, most things are blind.%^RESET%^",
	"abyss" : "%^BOLD%^%^BLUE%^Its so dark and cold down here.  Surely you want to swim %^CYAN%^up %^BLUE%^toward the surface and the light.%^RESET%^",
	"fish" : "%^BOLD%^%^BLUE%^You catch only the faint flicker of light as they dart by.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/seawreck_d4",
		"south" : "/d/av_rooms/lurue/seawreck_d7",
		"up" : "/d/av_rooms/lurue/seawreck_u7",
	]));



    set_invis_exits(({ "up" }));

}