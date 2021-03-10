#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v71",
	"east" : ROOMS+"e2829",
	"south" : ROOMS+"v73",
	"northwest" : ROOMS+"rb15",
	]) );
	set_invis_exits(({"east"}));
}
