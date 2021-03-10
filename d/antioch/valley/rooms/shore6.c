#include <std.h>
#include "../valley.h"
inherit C_SHORE1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"shore5",
	"east" : ROOMS+"shore7",
	"south" : ROOMS+"v46",
	]) );
}
