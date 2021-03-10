#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_SR_ONE;

void create() 
{
	::create();
	set_exits(([
		"north" : CAT_ROOMS"cat_first_room_3",
	] )); 
}
void long_desc() 
{	
	return ::long_desc() + "  %^BOLD%^%^RED%^An opening "+
	"leads out of this chamber to the north.%^RESET%^";
}

void reset()
{
	::reset();
	TO->add_gold();
}	

