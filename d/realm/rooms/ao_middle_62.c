#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["north" : MRS"61", 
	"south" : MRS"63"]));
}
