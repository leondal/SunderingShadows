#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"41", 
	"east" : MRS"43"]));
	wwall = "northern";
	//sexit = "north";
	hidden_room = MRS"134";	
}
