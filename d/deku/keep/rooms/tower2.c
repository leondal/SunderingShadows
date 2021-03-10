#include <std.h>
#include "../keep.h"
inherit HTOWER;
void create() {
    ::create();
   set_long(TO->query_long() + "  The chamber is dominated by a spiral, %^BOLD%^%^WHITE%^stone "+
		"staircase%^RESET%^ that leads to the level above or back to the level below.%^RESET%^");
   set_exits(([
       "up" : KEEPR + "tower3",
       "down" : KEEPR + "tower1"
    ] ));
}
