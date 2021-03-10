#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_BH;

void create() 
{
    	::create();
	wwall = "southern";
	sexit = "south";
	hidden_room = MRS"1";	
	set_exits((["east" : MRS"3", 
	"west" : MRS"13"]));
}
