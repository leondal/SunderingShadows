#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v39",
	"east" : ROOMS+"v41",
	"south" : ROOMS+"g85",
	"northwest" : ROOMS+"e2704",
	]) );
	set_invis_exits(({"northwest"}));
}
