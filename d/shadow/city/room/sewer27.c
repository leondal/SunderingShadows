//Titania 10/21/2019
//Shadow Sewers, Room 27

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_long("%^ORANGE%^This %^BOLD%^%^BLACK%^dank tunnel %^RESET%^%^ORANGE%^is "+ 
   "constructed out of ancient stout bricks that are covered in a patina of "+ 
   "%^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^i%^BOLD%^l%^BLACK%^t%^RESET%^%^GREEN%^h "+ 
   "%^ORANGE%^and %^BOLD%^%^GREEN%^sl%^BLACK%^i%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^ORANGE%^. "+ 
   "The tunnel is roughly half-circular in shape, measuring twenty feet across, "+ 
   "and almost twenty feet high at its apex. There are five foot wide walkways "+ 
   "on either side, allowing access all the way down the tunnel. Running down "+ 
   "the middle of the tunnel in between the walkways, is a %^BOLD%^%^BLACK%^culvert "+ 
   "%^RESET%^%^ORANGE%^containing the city's "+ 
   "%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^a%^GREEN%^s%^BOLD%^%^BLACK%^tewa%^RESET%^%^GREEN%^t%^ORANGE%^e%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^, "+ 
   "and who knows what else. Periodically, small pipes jut out of the walls of the tunnel "+ 
   "and hang over the edge of the culvert, allowing wastewater to drain. Access over "+ 
   "the culvert is offered by %^WHITE%^bridges %^ORANGE%^constructed "+ 
   "haphazardly out of wooden boards. Some crumbling bricks have allowed for a bit of a hole in the eastern wall.\n");
   add_item(({"hole"}),"%^GREEN%^Peering through the hole you see what looks to be a room on the other side. Perhaps you can enter it?%^RESET%^");
   set_exits(([
	  "enter" : ROOMS"sewer29",
	  "north" : ROOMS"sewer28",
	  "south" : ROOMS"sewer23",
   ]));
   add_invis_exit("enter");
}
