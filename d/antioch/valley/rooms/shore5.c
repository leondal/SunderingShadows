#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"v50",
	"east" : ROOMS+"shore6",
	"south" : ROOMS+"v45",
	"northwest" : ROOMS+"shore4",
	]) );
}
