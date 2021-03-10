// Chernobog (10/27/20)
// Entrance, Thief Tutorial Area

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
	set_name("The Thief Tutorial Entrance");
	set_short("%^BOLD%^%^WHITE%^T%^RESET%^h%^BOLD%^%^BLACK%^e %^WHITE%^G%^RESET%^u%^BOLD%^%^BLACK%^ild %^WHITE%^T%^RESET%^r%^BOLD%^%^BLACK%^aining %^WHITE%^G%^RESET%^r%^BOLD%^%^BLACK%^ounds%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^The first thing you notice on entering is that the walls are absolutely covered in all manner of %^RED%^g%^MAGENTA%^r%^ORANGE%^a%^GREEN%^f%^CYAN%^f%^BLUE%^i%^MAGENTA%^t%^RED%^i%^BLACK%^. Names have been %^RESET%^carved%^BOLD%^%^BLACK%^, %^RED%^painted%^BLACK%^, %^WHITE%^scrawled%^BLACK%^, and %^RESET%^%^MAGENTA%^marked %^BOLD%^%^BLACK%^on all four walls in a dizzying array of %^RED%^c%^ORANGE%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r%^MAGENTA%^s %^BLACK%^and styles. So eye-catching is it that the %^RESET%^%^BLUE%^hole %^BOLD%^%^BLACK%^in the stone floor is almost an afterthought, complete with a %^RESET%^%^ORANGE%^rope ladder %^BOLD%^%^BLACK%^leading down into the depths. There appears to be some %^WHITE%^writing %^BLACK%^painted around the circumference of the hole.%^RESET%^");
	set_smell("default","The smell of rich tobacco mixes with the damp coming up from below.");
	set_listen("default","You hear the occasional echo of dripping water.");
	set_items(([
		({"wall","walls"}) : "%^BOLD%^%^BLACK%^In the very few spots that haven't been vandalized, you can see the walls are %^RESET%^%^ORANGE%^wooden %^BOLD%^%^BLACK%^and apparently quite thick and sturdy.%^RESET%^",
		"floor" : "%^BOLD%^%^BLACK%^The floor is solid stone, worn smooth by countless footpads who have come before you. There is a %^RESET%^%^BLUE%^hole %^BOLD%^%^BLACK%^in the middle of the floor, and a %^RESET%^%^CYAN%^chill breeze %^BOLD%^%^BLACK%^rises up from it.%^RESET%^",
		"hole" : "%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^hole %^BOLD%^%^BLACK%^appears to have once been a natural fissure, but the thieves have widened it into a proper passage. A %^RESET%^%^ORANGE%^rope ladder %^BOLD%^%^BLACK%^leads downwards, and there is %^WHITE%^writing %^BLACK%^surrounding the hole in a circle.%^RESET%^",
		"ladder" : "%^BOLD%^%^BLACK%^Thick %^RESET%^%^ORANGE%^cord %^BOLD%^%^BLACK%^has been woven into a serviceable ladder, which has been bolted to the floor and left to hang down into the %^RESET%^%^BLUE%^hole%^BOLD%^%^BLACK%^.%^RESET%^",
		"writing" : "%^BOLD%^%^BLACK%^White paint has been used to surround the %^RESET%^%^BLUE%^hole %^BOLD%^%^BLACK%^with the message: %^WHITE%^Toss fresh fish down here! %^BLACK%^There are several arrows pointing into the depths to illustrate this point.%^RESET%^",
		({"graffiti","names"}) : "%^BOLD%^%^BLACK%^A multitude of names have been placed on the walls, often to the effect of %^WHITE%^'so-and-so was here!'%^BLACK%^. Many of them seem strange and unfamiliar, but here and there are names that can be heard %^RESET%^%^CYAN%^whispered %^BOLD%^%^BLACK%^in s%^RESET%^h%^BOLD%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET%^w%^BOLD%^y %^RESET%^c%^BOLD%^%^BLACK%^o%^RESET%^r%^BOLD%^n%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^s %^BOLD%^%^BLACK%^of the land. Even the greatest of thieves started as novices, once upon a time.%^RESET%^",
		]));
	set_exits(([
		"lounge" : "d/shadow/city/room/thieflounge",
		"down" : ROOMS"chamber1",
		]));
}

