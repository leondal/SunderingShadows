#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"palace10",
	"south" : ROOMS+"palace8",
	]));
}
