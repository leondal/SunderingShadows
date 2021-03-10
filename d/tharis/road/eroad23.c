#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"west" : ROOMS+"eroad22",
	"southeast" : ROOMS+"eroad24",
	]));
}
