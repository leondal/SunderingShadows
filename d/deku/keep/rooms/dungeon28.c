#include <std.h>
#include "../keep.h"
inherit STAIRWELL;

void create()
{
    	::create();
	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The stairwell "+
	"continues sharply upward and downward here.  You may go "+
	"either direction, but you must brave the unknown danger "+
	"of the thick darkness.%^RESET%^\n");
    	set_exits(([
		"up": KEEPR + "dungeon29","down" : KEEPR + "dungeon27"
    	] ));
}
