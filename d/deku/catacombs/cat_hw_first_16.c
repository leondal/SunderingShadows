#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_F;

void create() 
{
	mob_type = 2;
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues westward and "+
	"eastward here.");
	set_exits(([
		"west" : CAT_ROOMS"cat_hw_first_15",
		"east" : CAT_ROOMS"cat_hw_first_17"
	] )); 
}
