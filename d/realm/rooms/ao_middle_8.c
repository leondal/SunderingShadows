#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_MH;

void create() 
{
    	::create();
	wwall = "southern";
	hidden_room = MRS"102";
	set_exits((["west" : MRS"9", 
	"east" : MRS"7"]));
}
