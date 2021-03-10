#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_ROOM_ONE_F;

void create() 
{
	which_room = 3;
	::create();
	set_exits(([
		"west" : CAT_ROOMS"cat_hw_first_9"
	] )); 
}
