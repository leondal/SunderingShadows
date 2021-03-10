#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_BH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"125", "south" : MRS"52"]));
	wwall = "eastern";
	sexit = "east";
	hidden_room = MRS"55";	
}
