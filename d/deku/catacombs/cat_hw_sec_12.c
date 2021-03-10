#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_S;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues westward "+
	"and southward here.%^RESET%^");

	set_exits(([
		"south" : CAT_ROOMS"cat_hw_sec_11",
		"west" : CAT_ROOMS"cat_hw_sec_13"
	] )); 
	fix_exits();
}

