#include <std.h>
#include "../eroad.h"
inherit PATH;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"path4",
	"south" : ROOMS+"path2",
	]));
}
