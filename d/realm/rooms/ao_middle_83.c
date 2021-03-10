#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"82", "south" : MRS"84"]));
	wwall = "eastern";
	//sexit = "west";
	hidden_room = MRS"123";
}
