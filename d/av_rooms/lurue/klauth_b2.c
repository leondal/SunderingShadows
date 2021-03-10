// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("klauth_b2");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("shore");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^Bank of the River%^RESET%^");

    set_long("%^RESET%^%^CYAN%^You find yourself standing on the bank of a river that cuts its way through the tall %^BOLD%^%^BLACK%^mountains %^RESET%^%^CYAN%^at the center of this island, and flows down to the %^"
	"BLUE%^sea%^CYAN%^.  Wide at this spot, the river flows quickly toward the center but shallows out on either bank making it seem at least somewhat traversable.  Tiny %^ORANGE%^pebbles %^CYAN%^and the o"
	"ccasional larger %^BLACK%^%^BOLD%^rock %^RESET%^%^CYAN%^or %^WHITE%^boulder %^CYAN%^make up the bed and shores of this river, giving uneven ground for walking upon.  High above and further to the nort"
	"h you can see a %^ORANGE%^bridge %^CYAN%^spanning between the mountains, but it's too far away to reach or use, your only choice seems to be to find away across the river here.%^RESET%^"
	);

    set_smell("default","
The smell of salt air tickles your nose.");
    set_listen("default","You can hear the water flowing by in the swiftly river.");

    
set_items(([ 
	({ "rocks", "rock", "boulders", "boulder", "pebbles", "pebble" }) : "%^ORANGE%^Covering the bottom of the river and its banks are mostly small water rounded stones and pebbles, though there is the occasional larger boulder or rock that causes the river's current to be unpredictable and uncertain.  You only hope if you try to wade or swim across the river that you don't get caught up in one of those fast moving currents.%^RESET%^",
	({ "mountain", "stairs", "crater" }) : "%^BOLD%^%^BLACK%^To the north you can see mountains, at least one of which you traversed over to reach this place.  On the far one you can see that it has a large crater toward the top, likely the home of %^RED%^Klauth%^BLACK%^, the creature you are hunting.  Those stairs look inviting, almost encouraging considering the hardships of climbing over all these rocks.%^RESET%^",
	({ "sea", "water", "ocean" }) : "%^BOLD%^%^BLUE%^Looking out at the ocean, you can make out the great swells of water that roll in and out.  Further down, where the shoreline is, you see the occasional white spray of the water striking the boulders and rocks you just climbed over.%^RESET%^",
	"bridge" : "%^RESET%^%^ORANGE%^Suspended high above, between the two mountains, you can see a bridge that stretches over the river shaped crag.  It would likely be very easy to cross and would lead to those easy to climb stairs.  Although you recall what your trainer said once about the 'easy route'. %^RESET%^",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/lurue/klauth_m1",
		"swim" : "/d/av_rooms/lurue/klauth_b1",
	]));



    set_invis_exits(({ "swim" }));

}