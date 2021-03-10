#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;

void create() 
{
    	::create();
	set_exits((["north" : MRS"115", 
	"south" : MRS"113"]));
}
