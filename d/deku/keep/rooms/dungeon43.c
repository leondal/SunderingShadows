#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create() 
{
    	::create();

	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^This corridor "+
	"slopes downward to the east "+
	"and sharply upward to the west.  You may travel in "+
	"either direction, but you "+
	"must brave the unknown danger of the thick "+
	"%^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^.%^RESET%^\n");
 	set_exits(([
		"west": KEEPR + "dungeon44","east" : KEEPR + "dungeon42"
    	] ));
}
