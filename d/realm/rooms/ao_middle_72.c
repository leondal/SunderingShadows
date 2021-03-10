#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;

void create() 
{
    	::create();
	set_exits((["south" : MRS"71", "portal" : MRS"73"]));
	set_long(TO->query_long() + "%^BOLD%^%^BLACK%^  A "+
	"%^BOLD%^%^BLUE%^portal%^BOLD%^%^BLACK%^ rests against "+
	"the eastern wall here.%^RESET%^");
	add_item("portal", "%^BOLD%^%^BLUE%^This portal is glowing a "+
	"faint bluish color and you can tell that it leads to back into "+
	"the hallway of the keep.%^RESET%^");
}
