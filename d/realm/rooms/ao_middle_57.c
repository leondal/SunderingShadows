#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"56", 
	"east" : MRS"58"]));
	wwall = "northern";
	sexit = "north";
	hidden_room = MRS"31";
}
