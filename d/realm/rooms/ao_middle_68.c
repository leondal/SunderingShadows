#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_HALL;

void create() 
{
    	::create();
	set_exits((["north" : MRS"56", 
	"south" : MRS"67"]));
}
