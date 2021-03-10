#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"shore9",
	"east" : ROOMS+"v54",
	"south" : ROOMS+"v52",
	"north" : ROOMS+"shore11",
	"southeast" : ROOMS+"v53",
	]) );
}
