#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create() 
{
    	::create();
	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^This corridor slopes "+
	"downward to the southwest "+
	"and meets a narrow stairwell at the base of the northern wall.  "+
	"You may enter the stairwell or travel southward, regardless, "+
	"you must brave the unknown danger of the "+
	"thick %^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^.%^RESET%^\n");
	
    	set_exits(([
		"stairs": KEEPR + "dungeon21","southwest" : KEEPR + "dungeon19"
    	] ));
}
