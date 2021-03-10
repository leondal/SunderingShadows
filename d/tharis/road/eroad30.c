#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_exits(([
	"west" : ROOMS+"eroad29",
	"southwest" : ROOMS+"eroad31",
	]));
}
