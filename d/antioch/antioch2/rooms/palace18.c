#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"palace17",
	"south" : ROOMS+"palace19",
	]));
}
