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
%^ORANGE%^This is a bend in a little %^CYAN%^roa%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^ through the %^BOLD%^%^BLACK%^C%^RESET%^%^CYAN%^haru %^CYAN%^Mo%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^nt%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^n%^BLACK%^s%^RESET%^%^CYAN%^.%^ORANGE%^ To the southwest you can see that it straightens back out and back to the northeast is the road leading to the ruins of Antioch. The road is mostly dirt, though a few %^BOLD%^%^BLACK%^s%^BLACK%^t%^RESET%^%^CYAN%^on%^BOLD%^%^BLACK%^e%^BLACK%^s%^RESET%^%^ORANGE%^ have been set along the sides to help define it more. It is easily wide enough for several people to walk side by side.\n"
	);
	set("night long",
	"%^GREEN%^Road Through the Woods
%^BLUE%^The peaks of the %^BOLD%^%^BLACK%^C%^BLACK%^h%^RESET%^%^CYAN%^aru %^CYAN%^Mountains%^BLUE%^ are outlined by the moon. The forest seems more dangerous at night, the dark trees seem to crowd in close to the trail and cast strange shadows over the road. The road curves to the southwest here, but it appears to straighten out just up ahead. Back to the northeast is the road leading to the ruins of Antioch. %^CYAN%^Sto%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^es%^BLUE%^ line the path to either side, but it is basically a wide dirt trail that doesn't seem to be used very often.
\n"
	);
	set_smell("default","You smell the scent of pine trees mixed"+
	" with those of a large city.");
	set_listen("default","You can hear the faint sounds of a bustling"+
	" city.");
	set_items(([
	"mountains" : "The mountains extend as far as the eye can see.",
	({"road","little road","path","trail"}) : "The road runs to"+
	" the northeast and southwest. It is lined with stones on"+
	" and is not too very wide.",
	"stones" : "Large flat stones have been placed on either"+
	" side of the road to help define it.",
	({"trees","tree","pines"}) : "The trees are thick and tall"+
	" and block out a lot of the light, casting strange shadows"+
	" on the trail.",
	]));
	set_exits(([
	"northeast" : ROOMS+"trail4",
        "southwest" : ROOMS+"trail6",
	]));
}
