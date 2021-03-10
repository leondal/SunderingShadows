#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"32", 
	"east" : MRS"30"]));
	wwall = "southern";
	sexit = "south";
	hidden_room = MRS"57";
}
