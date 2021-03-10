#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"palace1",
	"west" : ROOMS+"palace20",
	"east" : ROOMS+"palace3",
	]));
}
