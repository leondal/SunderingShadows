#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"southwest" : ROOMS+"shore7",
	"east" : ROOMS+"shore10",
	"south" : ROOMS+"shore8",
	"northeast" : ROOMS+"shore11",
	"southeast" : ROOMS+"v52",
	]) );
}
