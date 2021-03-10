#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["south" : MRS"32", 
	"north" : MRS"34"]));
}
