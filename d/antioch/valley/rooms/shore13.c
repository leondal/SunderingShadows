#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"southwest" : ROOMS+"shore11",
	"east" : ROOMS+"shore14",
	"south" : ROOMS+"shore12",
	"southeast" : ROOMS+"v56",
	"northeast" : ROOMS+"shore15",
	]) );
}
