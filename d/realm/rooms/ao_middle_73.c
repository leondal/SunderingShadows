#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"74", "east" : MRS"88"]));
	wwall = "western";
	//sexit = "west";
	hidden_room = MRS"72";
}
