#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_UFT_BH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"104", "east" : MRS"35", 
	"south" : MRS"105"]));
	wwall = "western";
	sexit = "west";
	hidden_room = MRS"37";	
}
