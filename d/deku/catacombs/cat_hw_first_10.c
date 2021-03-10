#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_F;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues westward here.  "+
	"It opens into a larger room directly east of you.");
	set_exits(([
	"east" : CAT_ROOMS"cat_first_entry",
	"west" : CAT_ROOMS"cat_hw_first_11"
	] )); 
}
