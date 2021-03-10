#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"northwest" : ROOMS+"eroad17",
	"southeast" : ROOMS+"eroad19",
	]));
}
