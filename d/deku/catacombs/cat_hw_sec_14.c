#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_S;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues westward "+
	"and eastward here.%^RESET%^");

	set_exits(([
		"east" : CAT_ROOMS"cat_hw_sec_13",
		"west" : CAT_ROOMS"cat_hw_sec_15"
	] )); 
	fix_exits();
}

