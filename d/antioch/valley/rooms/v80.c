#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v81",
	"southwest" : ROOMS+"v82",
	"northeast" : ROOMS+"v78",
	"north" : ROOMS+"v79",
	"southeast" : ROOMS+"e2229",
	]) );
	set_invis_exits(({"southeast"}));
}
