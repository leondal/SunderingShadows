#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create() 
{
    	::create();
	
	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^This corridor "+
	"slopes downward to the northwest "+
	"and sharply upward to the southeast.  You may travel in either "+
	"direction, but you "+
	"must brave the unknown danger of the thick "+
	"%^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^"+
	".%^RESET%^\n");
	set_exits(([
		"southeast": KEEPR + "dungeon31","northwest" : KEEPR + "dungeon5"
    	] ));	
}
