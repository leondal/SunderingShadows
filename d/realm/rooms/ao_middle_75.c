#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"76", "south" : MRS"74"]));
	wwall = "western";
	sexit = "west";
	hidden_room = MRS"111";
}
