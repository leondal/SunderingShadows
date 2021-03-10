#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_CH;

void create() 
{
    	::create();
	set_exits((["south" : MRS"136"]));
	wwall = "eastern";
	sexit = "east";
	hidden_room = MRS"17";	
}
