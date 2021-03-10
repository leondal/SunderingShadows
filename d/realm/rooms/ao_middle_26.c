#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["south" : MRS"27", 
	"west" : MRS"25"]));
	wwall = "northern";
	sexit = "north";
	hidden_room = MRS"38";	
}
