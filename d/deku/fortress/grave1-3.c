#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
	int x;
 ::create();
 	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  A %^RESET%^stone wall%^BOLD%^%^WHITE%^"+
		" runs along the outside of the graveyard here.%^RESET%^");
 	for(x = 0;x < sizeof(SW_ITEM);x++) {
		add_item(SW_ITEM[x],"%^BOLD%^%^WHITE%^This pathetic stone wall is only around two feet "+
			"high and is mostly in a state of ruin.  It runs toward the east and the west here, "+
			"serving as a marker for the territory of the graveyard.%^RESET%^");
	}

  set_exits(([
			"east" : GY_ROOMS+"grave1-2",
  "north":GY_ROOMS +"grave2-3",
  "west" : GY_ROOMS +"grave1-4"
  ] ));
}
