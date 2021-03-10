#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;

void create() 
{
    	::create();
	set_exits((["east" : MRS"52", "portal" : MRS"46"]));
	set_long(TO->query_long() + "%^BOLD%^%^BLACK%^  A "+
	"%^BOLD%^%^BLUE%^portal%^BOLD%^%^BLACK%^ rests against "+
	"the western wall here.%^RESET%^");
	add_item("portal", "%^BOLD%^%^BLUE%^This portal is glowing a "+
	"faint bluish color and you can tell that it leads to back into "+
	"the hallway of the keep.%^RESET%^");
}
