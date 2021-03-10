#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"shore7",
	"east" : ROOMS+"v52",
	"south" : ROOMS+"v48",
	"north" : ROOMS+"shore9",
	"southeast" : ROOMS+"v49",
	]) );
}
