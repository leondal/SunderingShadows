#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Road Through the Woods");
	set_long(
	"%^GREEN%^Road Through the Woods
%^ORANGE%^This is a little %^CYAN%^ro%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^d%^ORANGE%^ through the %^CYAN%^Cha%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^u %^BOLD%^%^BLACK%^M%^RESET%^%^CYAN%^ounta%^BOLD%^%^BLACK%^i%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^s%^BLACK%^.%^RESET%^%^ORANGE%^ It runs east and west through the thick %^CYAN%^tre%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s.%^ORANGE%^ The road is mostly dirt, though a few %^CYAN%^stones%^ORANGE%^ have been set along the sides to help define it more. It is easily wide enough for several people to walk side by side. It curves to the south shortly up ahead.\n"
	);
	set("night long",
	"%^GREEN%^Road Through the Woods
%^BLUE%^The peaks of the %^CYAN%^Charu %^BOLD%^%^BLACK%^M%^RESET%^%^CYAN%^oun%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^ai%^BOLD%^%^BLACK%^n%^BLACK%^s%^RESET%^%^BLUE%^ are outlined by the moon. The forest seems more dangerous at night, the dark trees seem to crowd in close to the trail and cast strange shadows over the %^CYAN%^ro%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^d.%^BLUE%^ The road runs further to the west and it curves to the south shortly up ahead. %^BOLD%^%^BLACK%^S%^BLACK%^t%^BLACK%^o%^RESET%^%^CYAN%^ne%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^ line it to either side, but it is basically a wide dirt trail that doesn't seem to be used very often.\n"
	);
	set_smell("default","You smell the scent of pine trees.");
	set_listen("default","The wind whistles through the trees.");
	set_items(([
	"mountains" : "The mountains extend as far as the eye can see.",
	({"road","little road","path","trail"}) : "The road runs straight"+
	" east and west, it is lined with stones on the side and"+
	" not very wide.",
	"stones" : "Large flat stones have been placed on either"+
	" side of the road to help define it.",
	({"trees","tree","pines"}) : "The trees are thick and tall"+
	" and block out a lot of the light, casting strange shadows"+
	" on the trail.",
	]));
	set_exits(([
	"east" : ROOMS+"trail2",
	"west" : ROOMS+"trail4",
	]));
}
