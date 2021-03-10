#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"shore6",
	"east" : ROOMS+"shore8",
	"south" : ROOMS+"v47",
	"northeast" : ROOMS+"shore9",
	]) );
}
