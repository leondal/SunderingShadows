#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["east" : MRS"24", 
	"south" : MRS"34"]));
	wwall = "northern";
	sexit = "north";
	hidden_room = MRS"6";	
}
