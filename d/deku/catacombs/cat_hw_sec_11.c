#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_S;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues northward "+
	"and southward here.%^RESET%^");

	set_exits(([
		"south" : CAT_ROOMS"cat_hw_sec_10",
		"north" : CAT_ROOMS"cat_hw_sec_12"
	] )); 
	fix_exits();
}
