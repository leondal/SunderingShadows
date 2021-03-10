#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["south" : MRS"6", 
	"north" : MRS"4"]));
}
