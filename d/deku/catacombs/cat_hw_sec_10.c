#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_S;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues northward here."+
	"  It opens into a larger room directly south of you.%^RESET%^");

	set_exits(([
		"south" : CAT_ROOMS"cat_sec_entry",
		"north" : CAT_ROOMS"cat_hw_sec_11"
	] )); 
	fix_exits();
}

