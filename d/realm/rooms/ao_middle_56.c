#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["east" : MRS"57", 
	"south" : MRS"68"]));
}
