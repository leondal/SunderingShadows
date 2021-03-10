#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["west" : MRS"31", 
	"east" : MRS"29"]));
}
