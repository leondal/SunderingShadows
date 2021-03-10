#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_CH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"15"]));
	wwall = "western";
	sexit = "west";
	hidden_room = MRS"135";	
}
