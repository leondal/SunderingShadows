#include <std.h>
#include "../keep.h"

inherit STAIRWELL;

void create() 
{
	::create();
	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The stairwell "+
	"ends here, leaving you "+
	"with only one option, you must descend into the depths of the darkness.%^RESET%^\n");
	set_exits(([
       	"down" : KEEPR + "dungeon2"
    	] ));
}

