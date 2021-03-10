#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_S;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues northward and "+
	"westward here.%^RESET%^");

	set_exits(([
		"north" : CAT_ROOMS"cat_hw_sec_2",
		"west" : CAT_ROOMS"cat_hw_sec_4"
	] )); 
	fix_exits();
}
