// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tecqumin_05a");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("stairway");
    set_climate("temperate");

    set_short("%^RESET%^%^CYAN%^A narrow stairwell%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^A tapered stairwell leads deep into the earth, the sharp incline barely aided by the tall, narrow stairs formed from large squares of rock forced into the slanted earth. Like the stai"
	"rs the walls are affixed with slabs of %^RESET%^pale stone%^BOLD%^%^BLACK%^, stained by the elements till it is nearly black.  These wall slabs are decorated with %^RESET%^%^CYAN%^symbols%^BOLD%^%^BLA"
	"CK%^, %^RESET%^%^ORANGE%^faces %^BOLD%^%^BLACK%^and %^RESET%^figures %^BOLD%^%^BLACK%^all replicated with the same blocky styling that was found on the cover stone. Tendrils of %^RESET%^%^ORANGE%^root"
	"s %^BOLD%^%^BLACK%^snake out between the joints of these stones, dropping them in a cobweb if hair fine wisp. At the bottom of the stairs a chamber opens.%^RESET%^"
	);

    set_smell("default","
The air is musty with the smell of damp earth.");
    set_listen("default","Fresh air whistles by as it finds its way into this narrow passage.");

    
set_items(([ 
	({ "\tstairs", "stair", "block", "blocks" }) : "%^BOLD%^%^BLACK%^Large square blocks have been wedged into the earth, making a set of stairs that lead down into the dark chamber below.  Each block must weight a great amount as you can see several fracture points extending from where they rest one upon the other.  A few have even begun to crumble.%^RESET%^",
	({ "slabs", "slab", "pale stone", "stone", "stains", "wall", "walls" }) : "%^RESET%^You look closely at the walls and see that the pale stone was originally very intricately carved with several figures, faces and objects.  The stone has darkened under the attack of the elements and roots have dug into and broken apart many of the slabs, making it difficult to make out much at all.%^RESET%^",
	({ "figures", "figure" }) : "%^RESET%^The blocky forms of the figures you can make out, all appear to be in ceremonial garments including the fancy head and body jewelry which seems to be prevalent throughout the region.  More then one of the figures appears to have a pierced nose or ear, and almost all of them are wearing thick plates of gold and jade jewelry about their necks.  Oddly, they all appear to be looking away from the chamber below, as though they cannot gaze upon what is down there.%^RESET%^",
	({ "faces", "face" }) : "%^RESET%^%^ORANGE%^Only a few of the faces can be made out amongst the ruin that has come to this chamber.  Those faces all appear to be facing upward, toward the exit. Almost as though they are trying to avoid gazing upon what is below.%^RESET%^",
	({ "symbols", "symbol" }) : "%^RESET%^%^CYAN%^The symbols that you can make out appear to be similar to the blocky images seen above on the cover stone.  Many are repeated over and over again, and you can see that there is some sort of pattern to them, but exactly what that pattern is, isn't clear.%^RESET%^",
	({ "roots", "root", "cobwebs", "cobweb" }) : "%^RESET%^%^ORANGE%^Like a fine network of living cobwebs, the rooms spill out of every crevice and crawl along the surface of the stones.  Some hang down from the ceiling, clinging to your head and getting in your way of seeing.  This chamber must be ancient for as thick as these roots are.%^RESET%^",
	"chamber" : "%^RESET%^%^BLUE%^You can't make out much of what is below, but a part of you feels like maybe now would be a good idea to leave.  All the figures in this room are looking away from what is below.  Maybe you should too.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/tecqumin_05",
		"down" : "/d/av_rooms/lurue/tecqumin_05b",
	]));

}