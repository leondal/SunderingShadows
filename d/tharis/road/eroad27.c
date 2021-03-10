#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"southwest" : ROOMS+"eroad28",
	"northeast" : ROOMS+"eroad26",
	]));
}
