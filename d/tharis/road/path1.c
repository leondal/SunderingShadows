#include <std.h>
#include "../eroad.h"
inherit PATH;

void create()
{
	::create();
	set_exits(([
	"southeast" : ROOMS+"eroad36",
	"north" : ROOMS+"path2",
	]));
}
