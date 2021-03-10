// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_d9");
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
	"ted to this dark realm.  Despite the lack of light, you can sense a %^BLACK%^structure%^BLUE%^ nearby, rising up toward the surface and disturbing the water currents.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The sound of bubbles escaping from your mouth are the only thing you hear.");

    set_search("wood","%^RESET%^%^ORANGE%^You feel around further, following the smooth lines of the wood until you reach jagged, broken %^RED%^edge%^ORANGE%^.  Feeling closer, you realize that this must be a large part of the ship wreck you saw above.  You could probably search around for treasure, if you could find a way inside.%^RESET%^");
    set_search("structure","%^BOLD%^%^BLACK%^The structure is large and covered in the sharp formation of coral and rock.  Oddly a part of it seems to be made of %^RESET%^%^ORANGE%^wood%^BOLD%^%^BLACK%^.  Maybe if you searched further you could figure out why one part is different.%^RESET%^");
    set_search("edge","%^RED%^Cracks and broken edges guide your hands and eventually you find a %^BLACK%^%^BOLD%^passage%^RESET%^%^RED%^ that is wide enough to allow entrance.%^RESET%^");
    
set_items(([ 
	({ "darkness", "dark" }) : "%^BOLD%^%^BLACK%^Even in this darkness, most things are blind.%^RESET%^",
	"abyss" : "%^BOLD%^%^BLUE%^Its so dark and cold down here.  Surely you want to swim %^CYAN%^up %^BLUE%^toward the surface and the light.%^RESET%^",
	"fish" : "%^BOLD%^%^BLUE%^You catch only the faint flicker of light as they dart by.%^RESET%^",
	"structure" : "%^BOLD%^%^BLACK%^You can't make it out in the darkness, but you're sure if you searched about, you could feel where it was.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/seawreck_d7",
		"passage" : "/d/av_rooms/lurue/seawreck_b2",
	]));



    set_invis_exits(({ "passage" }));

}