#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"shore11",
	"east" : ROOMS+"v56",
	"south" : ROOMS+"v54",
	"north" : ROOMS+"shore13",
	"southeast" : ROOMS+"v55",
	]) );
}
