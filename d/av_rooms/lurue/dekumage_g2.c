// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_g2");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("marsh");
    set_travel("game track");
    set_climate("tropical");

    set_short("%^RESET%^%^ORANGE%^A marshy path%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Thick springs of %^CYAN%^para grass %^GREEN%^and %^BOLD%^alligator weed %^RESET%^%^GREEN%^grow high through here, while the sagging limbs of the %^ORANGE%^cypress trees %^GREEN%^drip"
	" heavy gouts of sickly green %^BLACK%^%^BOLD%^moss%^RESET%^%^GREEN%^.  Together, these plants along with other harder to identify brush, obscure your view of the surroundings.  Only the thin %^ORANGE%"
	"^trail%^GREEN%^, barely wider then a game trail, offers any means of progressing through this thick bramble and the swampy marsh that springs up around you.  %^RESET%^"
	);

    set_smell("default","
The heavy smell of rotten vegetation hangs in the air.");
    set_listen("default","The air is alive with the heavy drone of insects.");

    
set_items(([ 
	({ "grass", "para grass", "weed", "alligator weed", "plants", "brush" }) : "%^BOLD%^%^GREEN%^The brush and weeds grow close together, obscuring the water and leaving only a faint trail for you to follow through the marshy lands. %^RESET%^",
	({ "water", "marsh" }) : "%^BOLD%^%^BLUE%^It is difficult to make out the water bellow the thick tangle of weeds, but the spongy ground reflects just how damp this area is.  Best to watch your step or you might vanish into the stagnant waters.%^RESET%^",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/lurue/dekumage_g3",
		"northwest" : "/d/av_rooms/lurue/dekumage_g1",
	]));

}