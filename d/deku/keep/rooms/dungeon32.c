#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create()
{
    	::create();
	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^This corridor slopes "+
	"downward to the northwest and meets a narrow stairwell at the base "+
	"of the southern wall.  You may enter the "+
	"stairwell or travel northward, regardless, you must brave "+
	"the unknown danger of the "+
	"thick %^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^.%^RESET%^\n");

	set_exits(([
		"stairs": KEEPR + "dungeon33","northwest" : KEEPR + "dungeon31"
    	] ));	
}

