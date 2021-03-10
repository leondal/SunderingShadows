#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_BH;

void create() 
{
    	::create();
	wwall = "eastern";
	sexit = "east";
	hidden_room = MRS"20";	
	set_exits((["south" : MRS"5", 
	"north" : MRS"3"]));
}
