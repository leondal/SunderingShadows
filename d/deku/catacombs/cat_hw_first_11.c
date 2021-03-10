#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_F;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues eastward and "+
	"westward here.");
	set_exits(([
	"east" : CAT_ROOMS"cat_hw_first_10",
	"west" : CAT_ROOMS"cat_hw_first_12"
	] )); 
}

