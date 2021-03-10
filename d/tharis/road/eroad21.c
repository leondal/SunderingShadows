#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"west" : ROOMS+"eroad20",
	"southeast" : ROOMS+"eroad22",
	]));
}
