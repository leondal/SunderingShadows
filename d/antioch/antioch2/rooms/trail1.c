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
%^ORANGE%^This little %^CYAN%^ro%^BOLD%^%^BLACK%^a%^BLACK%^d%^RESET%^%^ORANGE%^ through the %^BOLD%^%^BLACK%^C%^BLACK%^h%^RESET%^%^CYAN%^ar%^BOLD%^%^BLACK%^u%^RESET%^ %^CYAN%^Mou%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^ta%^BOLD%^%^BLACK%^i%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^ leads away from what is now the ruins of Antioch. It runs east and west through the thick %^BOLD%^%^BLACK%^t%^RESET%^%^GREEN%^r%^BOLD%^%^BLACK%^e%^BLACK%^e%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^.%^RESET%^%^ORANGE%^ The road is mostly dirt, though a few %^CYAN%^s%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^on%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s%^ORANGE%^ have been set along the sides to help define it more. It is easily wide enough for several people to walk side by side.\n"
	);
	set("night long",
	"%^BLUE%^The peaks of the %^CYAN%^Char%^BOLD%^%^BLACK%^u%^RESET%^ %^CYAN%^Mount%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^s%^BLUE%^ are outlined by the moon. The forest seems more dangerous at night, the dark %^GREEN%^t%^BOLD%^%^BLACK%^r%^BLACK%^e%^RESET%^%^GREEN%^es%^BLUE%^ seem to crowd in close to the trail and cast strange shadows over the %^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^oad%^BOLD%^%^BLACK%^.%^RESET%^%^BLUE%^ Back to the east are the ruins of Antioch. The road runs further to the west and it is not very big. %^BOLD%^%^BLACK%^S%^RESET%^%^CYAN%^ton%^BOLD%^%^BLACK%^e%^BLACK%^s%^RESET%^%^BLUE%^ line it to either side, but it is basically a wide dirt trail that doesn't seem to be used very often.\n"
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
   "east" : "/d/antioch/ruins/rooms/gates",
   "southeast" : "/d/antioch/wild/mount/pass_6",
	"west" : ROOMS+"trail2",
	]));
}
