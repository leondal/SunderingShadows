#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"southwest" : ROOMS+"eroad24",
	"southeast" : ROOMS+"eroad26",
	]));
}
