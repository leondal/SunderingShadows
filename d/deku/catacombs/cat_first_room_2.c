#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_ROOM_ONE_F;

void create() 
{
	which_room = 2;
	::create();
	set_exits(([
		"south" : CAT_ROOMS"cat_hw_first_6"
	] )); 
}

