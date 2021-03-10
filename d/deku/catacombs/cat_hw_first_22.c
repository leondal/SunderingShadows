#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_F;

void create() 
{
	mob_type = 2;
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues northward and "+
	"southward here.%^RESET%^");
	set_exits(([
		"south" : CAT_ROOMS"cat_hw_first_23",
		"north" : CAT_ROOMS"cat_hw_first_21"
	] )); 
}
