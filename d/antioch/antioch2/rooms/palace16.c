#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"palace15",
	"south" : ROOMS+"palace17",
	]));
}
