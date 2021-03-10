#include <std.h>
#include "../valley.h"
inherit C_SHORE1;

void create()
{
	::create();
	set_exits( ([
	"southwest" : ROOMS+"shore9",
	"east" : ROOMS+"shore12",
	"south" : ROOMS+"shore10",
	"northeast" : ROOMS+"shore13",
	"southeast" : ROOMS+"v54",
	]) );
}
