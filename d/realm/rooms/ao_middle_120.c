#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;

void create() 
{
    	::create();
	set_exits((["east" : MRS"121", 
	"west" : MRS"119"]));
}
