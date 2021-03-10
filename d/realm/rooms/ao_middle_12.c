#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	wwall = "northern";
	hidden_room = MRS"122";
	set_exits((["east" : MRS"13", 
	"south" : MRS"11"]));
}
