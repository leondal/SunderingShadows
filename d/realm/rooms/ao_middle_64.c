#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["west" : MRS"65", 
	"east" : MRS"63"]));
}
