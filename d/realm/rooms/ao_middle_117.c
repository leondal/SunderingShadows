#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;

void create() 
{
    	::create();
	set_exits((["east" : MRS"118", 
	"south" : MRS"116"]));
}
