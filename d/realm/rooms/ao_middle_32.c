#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["east" : MRS"31", 
	"north" : MRS"33"]));
	wwall = "western";
	//sexit = "south";
	hidden_room = MRS"35";
}
