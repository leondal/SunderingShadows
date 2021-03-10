#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create()
{
    	::create();
    	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^This corridor slopes "+
	"downward to the east and meets a narrow stairwell at the base of "+
	"the western wall.  You may enter the "+
	"stairwell or travel eastward, regardless, you must brave the "+
	"unknown danger of the "+
	"thick %^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^.%^RESET%^\n");

    	set_exits(([
		"stairs": KEEPR + "dungeon45","east" : KEEPR + "dungeon43"
    	] ));
}
