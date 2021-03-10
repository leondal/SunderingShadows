#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_ROOM_ONE_F;

void create() 
{
	which_room = 4;
	::create();
	set_exits(([
		"east" : CAT_ROOMS"cat_hw_first_12"
	] )); 
}

