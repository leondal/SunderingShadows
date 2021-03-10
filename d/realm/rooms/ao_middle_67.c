#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["south" : MRS"66", 
	"north" : MRS"68"]));
	wwall = "western";
	//sexit = "east";
	hidden_room = MRS"108";
}
