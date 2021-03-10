#include <std.h>
#include "../keep.h"

inherit STAIRWELL;

void create()
{
    	::create();
	
	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The stairwell ends "+
	"here, exiting into a larger chamber.  You may either exit "+
	"the stairwell or ascend the stairs, "+
	"regardless, you must brave the unknown danger of the "+
	"thick darkness.%^RESET%^\n");
 
    	set_exits(([
		"up": KEEPR + "dungeon40","exit" : KEEPR + "dungeon38"
    	] ));
}
