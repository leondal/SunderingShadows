#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_BH;

void create() 
{
    	::create();
	set_exits((["east" : MRS"21"]));
	wwall = "western";
	sexit = "west";
	hidden_room = MRS"4";
}
