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
%^ORANGE%^This is a little %^CYAN%^road%^ORANGE%^ through the %^CYAN%^C%^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^aru %^CYAN%^Mou%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^n%^BLACK%^s%^RESET%^%^CYAN%^.%^ORANGE%^ It curves to the southwest and back to the east are the ruins of Antioch. The road is mostly dirt, though a few %^CYAN%^s%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^ones%^ORANGE%^ have been set along the sides to help define it more. It is easily wide enough for several people to walk side by side.\n"
	);
	set("night long",
	"%^GREEN%^Road Through the Woods
%^BLUE%^The peaks of the %^CYAN%^Charu %^CYAN%^M%^BOLD%^%^BLACK%^o%^BLACK%^u%^BLACK%^n%^RESET%^%^CYAN%^tai%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^s%^BLUE%^ are outlined by the moon. The forest seems more dangerous at night, the dark %^CYAN%^trees%^BLUE%^ seem to crowd in close to the trail and cast strange shadows over the %^CYAN%^road%^BOLD%^%^BLACK%^.%^RESET%^%^BLUE%^ The road bends to the southwest here, back to the east are the ruins of Antioch. %^CYAN%^St%^BOLD%^%^BLACK%^o%^BLACK%^n%^BLACK%^e%^BLACK%^s%^RESET%^%^BLUE%^ line the path to either side, but it is basically a wide dirt trail that doesn't seem to be used very often.\n"
	);
	set_smell("default","You smell the scent of pine trees.");
	set_listen("default","The wind whistles through the trees.");
	set_items(([
	"mountains" : "The mountains extend as far as the eye can see.",
	({"road","little road","path","trail"}) : "The road curves"+
	" to the southwest here. It is lined with stones on the side and"+
	" is not very wide.",
	"stones" : "Large flat stones have been placed on either"+
	" side of the road to help define it.",
	({"trees","tree","pines"}) : "The trees are thick and tall"+
	" and block out a lot of the light, casting strange shadows"+
	" on the trail.",
	]));
	set_exits(([
	"east" : ROOMS+"trail3",
	"southwest" : ROOMS+"trail5",
	]));
}
