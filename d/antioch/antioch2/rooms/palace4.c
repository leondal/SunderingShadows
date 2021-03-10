#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"west" : ROOMS+"palace3",
	"east" : ROOMS+"palace6",
	"north" : ROOMS+"palace5",
	]));
}
