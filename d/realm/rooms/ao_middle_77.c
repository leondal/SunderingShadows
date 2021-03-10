#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"76", "east" : MRS"81"]));
	wwall = "northern";
	//sexit = "west";
	hidden_room = MRS"78";
}
