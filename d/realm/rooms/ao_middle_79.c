#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_BH;

void create() 
{
    	::create();
	set_exits((["south" : MRS"78"]));
	wwall = "eastern";
	sexit = "east";
	hidden_room = MRS"80";	
}
