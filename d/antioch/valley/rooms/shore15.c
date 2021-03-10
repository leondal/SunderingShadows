#include <std.h>
#include "../valley.h"
inherit C_SHORE1;

void create()
{
	::create();
	set_exits( ([
	"southwest" : ROOMS+"shore13",
	"east" : ROOMS+"rb1",
	"south" : ROOMS+"shore14",
	"southeast" : ROOMS+"v60",
	]) );
}
