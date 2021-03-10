#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;

void create() 
{
    	::create();
	set_exits((["west" : MRS"112", 
	"north" : MRS"18", 
	"south" : MRS"16", 
	"east" : MRS"14"]));
}
