//Titania 10/21/2019
//Shadow Sewers, Room 40

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_long("%^RESET%^%^BLUE%^The tunnel ends here, the %^GREEN%^grimy water %^BLUE%^spilling out "+ 
   "into the Saracosta River. Large pieces of debris have piled up against a "+ 
   "heavy %^BOLD%^%^BLACK%^mesh grate %^RESET%^%^BLUE%^that blocks the opening. "+ 
   "Outside of the tunnel you can see across the %^CYAN%^river %^BLUE%^to the sunken "+ 
   "remains of an ancient %^BOLD%^%^BLACK%^tower%^RESET%^%^BLUE%^. You can see some "+ 
   "ship hauls bobbing in the water here, and you suspect you must be beneath "+ 
   "the docks of the city.\n%^WHITE%^");
   set_smell("default","The scent of the passing river and the city overhead come as a relief.");
   set_listen("default","You hear sounds of the city overhead coupled with the sounds of creaking ships and the swiftly flowing river.");
	set_items(([
	({"grate"}) : "%^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^The grate has come detached from the tunnel near the top, and you wonder if it might be possible to climb up onto the docks from here.%^RESET%^",
	({"tower"}) : "%^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^Remnants of an ancient bastion submerged under the water can be seen here.%^RESET%^",
	({"ships","hulls"}) : "%^CYAN%^While you can't see much of the ships from this vantage point, you can see the grimy hulls of these seaworthy vessels crowding around.%^WHITE%^",
   ]));
   set_exits(([
	  "north" : ROOMS"sewer39",
   ]));
    set_climb_exits((["climb":({ROOMS"dock1",20,4,100})
]));
}
