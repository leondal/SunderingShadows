#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_F;

void create() 
{
	mob_type = 2;
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues northward "+
	"here.  It opens into a larger room directly south of you.%^RESET%^");
	set_exits(([
		"south" : CAT_ROOMS"cat_first_room_6",
		"north" : CAT_ROOMS"cat_hw_first_22"
	] )); 
}
