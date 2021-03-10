#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_FH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"110"]));
	wwall = "eastern";
	sexit = "east";
	hidden_room = MRS"75";
}
