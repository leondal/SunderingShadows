#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_FH;

void create() 
{
    	::create();
	set_exits((["east" : MRS"110"]));
	wwall = "western";
	sexit = "west";
	hidden_room = MRS"60";
}
