#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"shore13",
	"east" : ROOMS+"v60",
	"south" : ROOMS+"v56",
	"north" : ROOMS+"shore15",
	"southeast" : ROOMS+"v57",
	]) );
}
