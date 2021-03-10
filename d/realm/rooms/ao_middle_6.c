#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"7", 
	"north" : MRS"5"]));
	wwall = "southern";
	sexit = "south";
	hidden_room = MRS"23";	
}
