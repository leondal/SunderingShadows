#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_SR_ONE;

void create() 
{
	::create();
	set_exits(([
		"south" : CAT_ROOMS"cat_first_room_4",
	] )); 
}
void long_desc() 
{	
	return ::long_desc() + "  %^BOLD%^%^RED%^An opening "+
	"leads out of this chamber to the south.%^RESET%^";
}

void reset()
{
	::reset();
	TO->add_gold();
}	

