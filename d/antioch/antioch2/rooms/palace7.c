#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"south" : ROOMS+"palace6",
	"north" : ROOMS+"palace8",
	]));
}
