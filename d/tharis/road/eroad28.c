#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"northeast" : ROOMS+"eroad27",
	"southeast" : ROOMS+"eroad29",
	]));
}
