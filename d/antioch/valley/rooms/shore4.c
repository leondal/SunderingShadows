#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"shore16",
	"south" : ROOMS+"v50",
	"southeast" : ROOMS+"shore5",
   "northwest" : ROOMS+"shore3",
	]) );
}
