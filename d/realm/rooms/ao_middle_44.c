#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_BH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"43", 
	"south" : MRS"45"]));
	wwall = "northern";
	sexit = "north";
	hidden_room = MRS"50";	
}
