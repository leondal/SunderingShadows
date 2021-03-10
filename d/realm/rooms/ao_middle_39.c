#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_BH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"40", 
	"south" : MRS"38"]));
	wwall = "western";
	sexit = "west";
	hidden_room = MRS"97";	
}
