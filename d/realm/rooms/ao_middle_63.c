#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"64", 
	"north" : MRS"62"]));
	wwall = "eastern";
	//sexit = "east";
	hidden_room = MRS"69";
}
