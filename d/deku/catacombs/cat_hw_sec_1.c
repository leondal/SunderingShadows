#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_S;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues southward here.  "+
	"It opens into a larger room directly north of you.%^RESET%^");

	set_exits(([
		"north" : CAT_ROOMS"cat_sec_entry",
		"south" : CAT_ROOMS"cat_hw_sec_2"
	] )); 
	fix_exits();
}

