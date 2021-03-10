#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_BH;

void create() 
{
    	::create();
	set_exits((["east" : MRS"60", 
	"west" : MRS"57"]));
	wwall = "southern";
	sexit = "south";
	hidden_room = MRS"59";
}
