#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["south" : MRS"29", 
	"north" : MRS"27"]));
	wwall = "eastern";
	//sexit = "north";
	hidden_room = MRS"101";	
}
