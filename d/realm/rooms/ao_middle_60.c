#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_FH;

void create() 
{
    	::create();
	set_exits((["west" : MRS"58", 
	"south" : MRS"61"]));
	wwall = "eastern";
	sexit = "east";
	hidden_room = MRS"109";
}
