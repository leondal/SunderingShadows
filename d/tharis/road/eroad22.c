#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"northwest" : ROOMS+"eroad21",
	"east" : ROOMS+"eroad23",
	]));
}
