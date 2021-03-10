#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["north" : MRS"45", 
	"south" : MRS"47"]));
	wwall = "eastern";
	//sexit = "north";
	hidden_room = MRS"51";	
}
