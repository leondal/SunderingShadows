#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;

void create() 
{
    	::create();
	set_exits((["south" : MRS"122", 
	"west" : MRS"120"]));
}
