// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("klauth_p5");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("shore");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Grasslands of Aramanth%^RESET%^");

    set_long("%^RESET%^You make your way up and away from the shoreline, leaving the foul smell of rotting %^GREEN%^seaweed %^RESET%^and other less identifiable things and start to trek through the %^ORANGE%^thick "
	"grass %^RESET%^of the upper banks.  To the southeast you can see the %^BLUE%^Sea %^RESET%^in all its glory and ahead to the northeast a %^CYAN%^river %^RESET%^winds its way down to an inlet.  Cutting "
	"its way between%^BOLD%^%^BLACK%^ mountains%^RESET%^.  High above you can see a %^ORANGE%^bridge %^RESET%^spanning this chasm, but it would require a lot of climbing to reach, you only hope that there "
	"is a way across the %^CYAN%^river %^RESET%^that can be crossed this far down the mountain.%^RESET%^"
	);

    set_smell("default","
The air is rank with the smell of rotten seaweed.");
    set_listen("default","You hear the sound of the ocean.");

    
set_items(([ 
	({ "sea", "water", "ocean" }) : "%^BOLD%^%^BLUE%^Looking out at the ocean, you can make out the great swells of water that roll in and out.  Further down, where the shoreline is, you see the occasional white spray of the water striking the boulders and rocks you just climbed over.%^RESET%^",
	({ "mountain", "stairs", "crater" }) : "%^BOLD%^%^BLACK%^To the north you can see mountains, at least one of which you traversed over to reach this place.  On the far one you can see that it has a large crater toward the top, likely the home of %^RED%^Klauth%^BLACK%^, the creature you are hunting.  Those stairs look inviting, almost encouraging considering the hardships of climbing over all these rocks.%^RESET%^",
	"grass" : "%^GREEN%^The thick rushes of coarse, sharp edged grass snags at your clothing and tears at your skin, making it difficult to traverse the area.  Growing up along the edges of the shorline, far enough back to avoid the highest of tides, this tall grass waves in the constant breeze that flows in off the sea.%^RESET%^",
	"river" : "%^RESET%^%^CYAN%^Cutting through the mountains that jut up from the center of this island, you can see a wide river.  It is over this river that the bridge stretches, though that's much further up the mountains and far out of your current reach or use.  Hopefully the river is shallow enough to %^RESET%^swim%^CYAN%^ ahead, otherwise you'll have come this way for no reason.%^RESET%^",
	"bridge" : "%^RESET%^%^ORANGE%^Suspended high above, between the two mountains, you can see a bridge that stretches over the river shaped crag.  It would likely be very easy to cross and would lead to those easy to climb stairs.  Although you recall what your trainer said once about the 'easy route'. %^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/klauth_p4",
		"east" : "/d/av_rooms/lurue/klauth_b1",
	]));

}