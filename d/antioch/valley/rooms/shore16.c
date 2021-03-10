#include <std.h>
#include "../valley.h"
inherit C_SHORE1;

void create()
{
	::create();
	set_exits( ([
	"north" : ROOMS+"shore3",
	"south" : ROOMS+"v51",
	"east" : ROOMS+"shore4",
	]) );
}
