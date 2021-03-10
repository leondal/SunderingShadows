#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"southwest" : ROOMS+"eroad19",
	"east" : ROOMS+"eroad21",
	]));
}
