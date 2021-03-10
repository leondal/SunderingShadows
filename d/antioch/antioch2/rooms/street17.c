//Updated for better mapping. Kismet.
//Ready to be installed: Proper path is: /d/antioch/antioch2/rooms/street17 Kismet.

#include <std.h>
#include "../antioch.h"
#include <daemons.h>
inherit CVAULT;

void create()
{
	set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1 }));
	::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^ORANGE%^Crescent%^RESET%^ Street");
	set_long("You are on %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^.\n"+
"%^WHITE%^There is a little %^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^use%^RESET%^%^WHITE%^ to the west. A strong scent of dried meats and fruits seems to come from within it. To the northeast you can see a very large stone church that causes the %^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^t%^BOLD%^%^ORANGE%^reet%^RESET%^%^WHITE%^ to turn to the north. To the southwest is the intersection of %^ORANGE%^Crescent%^RESET%^ and %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street%^RESET%^ not far from the Antioch gates.
"
	);
	set_smell("default","You can smell dried meat and fruits.");
	if(query_night() == 1) {
		set_listen("default","You hear gentle snores coming from inside the little house.");
		}
	else {
		set_listen("default","The hustle and bustle of a busy city is all around you.");
	}
	set_items(([
		({"street","cobblestones","cobbles","road","path"}) : "The street is paved with cobblestones.",
		"street sign" : "This is %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^.",
		({"house","building","shop"}) : "It is a small little wooden house with a pretty brown roof.",
		"church" : "There is a very impressive stone church to the northeast.",
	]));
	set_exits(([
		"northeast" : ROOMS+"street16",
		"southwest" : ROOMS+"street2",
		"west" : ROOMS+"ration",
	]));
	set_door("door",ROOMS+"ration","west",0);
		if(query_night() == 1) {
			set_open("door",0);
			"/d/antioch/antioch2/rooms/ration"->set_open("door",0);
		}
		else if(query_night() != 1) {
			set_open("door",1);
			"/d/antioch/antioch2/rooms/ration"->set_open("door",1);
	}
}
