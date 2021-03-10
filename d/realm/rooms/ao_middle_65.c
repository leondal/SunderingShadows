#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["west" : MRS"66", 
	"east" : MRS"64"]));
}
