#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_F;

void create() 
{
	::create();
	set_long(TO->query_long() + "  %^YELLOW%^The tunnel continues southward here.  "+
	"It opens into a larger room directly north of you.%^RESET%^");
	set_exits(([
	"north" : CAT_ROOMS"cat_first_entry",
	"south" : CAT_ROOMS"cat_hw_first_2"
	] )); 
}
