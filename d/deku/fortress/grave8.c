#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
	int x;
  ::create();
	 set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  A %^RESET%^stone wall%^BOLD%^%^WHITE%^"+
		" runs along the outside of the graveyard here.  A wide gap in the wall "+
        "to the north leads to a forboding mausoleum.%^RESET%^");

	for(x = 0;x < sizeof(SW_ITEM);x++) {
	 	add_item(SW_ITEM[x],"%^BOLD%^%^WHITE%^This pathetic stone wall is only around two feet "+
			"high and is mostly in a state of ruin.  It runs toward the west and the south here, "+
			"serving as a marker for the territory of the graveyard.%^RESET%^");
	 }
 set_exits(([
   "south":GY_ROOMS +"grave7",
   "west" : GY_ROOMS +"grave8-1",
   "north" : "/d/deku/mausoleum/rooms/mausoleum",
  ] ));
}
