#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"northeast" : ROOMS+"eroad30",
	"southeast" : ROOMS+"eroad32",
	]));
}
