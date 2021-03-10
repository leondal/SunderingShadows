#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_BH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"136"]));
	wwall = "southern";
	sexit = "south";
	hidden_room = MRS"138";	
}
