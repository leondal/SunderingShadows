#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"39", 
	"east" : MRS"49"]));
	wwall = "southern";
	sexit = "south";
	hidden_room = MRS"26";	
}
