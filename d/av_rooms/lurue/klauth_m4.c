// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("klauth_m4");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("shore");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Side of Klauth's Mountain%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The sheer rock of this mountain leaves little for you to cling to as you climb up its face.  Narrow %^RESET%^ledges%^BOLD%^%^BLACK%^, small %^RESET%^%^ORANGE%^handholds%^BOLD%^%^BLACK"
	"%^, loose %^RESET%^%^CYAN%^rocks %^BOLD%^%^BLACK%^all contribute to your climb, yet at any moment one or more might give out.  From here you can see the %^BLUE%^river %^BLACK%^down below and beyond it"
	", stretching out the %^BLUE%^ocean%^BLACK%^.  High above, at the top of the mountain, a %^RED%^crater %^BLACK%^looms.%^RESET%^"
	);

    set_smell("default","
An occasional breeze brings the hint of sea air.");
    set_listen("default","The sound of loose rocks skittering down the mountainside fill the air.");

    
set_items(([ 
	({ "ledges", "handholds", "ledge", "handhold", "rocks", "rock" }) : "%^BOLD%^%^BLACK%^Climbing this mountain is no easy feat, but thankfully there are enough handholds and ledges to support your climb.  Though many are spaced out and several have loose rocks associated with them, there are also a good number of safe spots as well.  At least you hope they're safe as you catch your breath and pick the next ledge to climb to.%^RESET%^",
	({ "sea", "water", "ocean" }) : "%^BOLD%^%^BLUE%^Looking out at the ocean, you can make out the great swells of water that roll in and out.  Further down, where the shoreline is, you see the occasional white spray of the water striking the boulders and rocks you just climbed over.%^RESET%^",
	({ "mountain", "crater" }) : "%^BOLD%^%^BLACK%^The mountain is huge and a daunting task to climb.  Much of it is sheer and nearly vertical, though there are places where small ledges jut outward and other spots where a trail almost widens.  You only hope that this good fortune continues all the way up to the crater at the top, where Klauth is rumored to live.%^RESET%^",
	"river" : "%^BLUE%^%^BOLD%^Down below you can see the river winding its way through the center mountains of this island.  The deep waters seeming too shallow to catch and protect you if you fall.  A few boulders loom up out of the water adding additional worry that if you do slip you could land upon one and break something vital.  Best to concentrate on the climb, rather then the fall.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/klauth_m3",
		"east" : "/d/av_rooms/lurue/klauth_m5",
	]));

}