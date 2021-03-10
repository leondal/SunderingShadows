#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_BH;

void create() 
{
    	::create();
	set_exits((["south" : MRS"15"]));
	wwall = "northern";
	sexit = "north";
	hidden_room = MRS"19";	
}
