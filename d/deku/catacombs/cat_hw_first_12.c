#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_F;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues eastward here.  "+
	"It opens into a larger room directly west of you.");
	set_exits(([
	"west" : CAT_ROOMS"cat_first_room_4",
	"east" : CAT_ROOMS"cat_hw_first_11"
	] )); 
}
