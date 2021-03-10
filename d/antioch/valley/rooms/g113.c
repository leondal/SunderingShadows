#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g114",
	"east" : ROOMS+"m2",
	"north" : ROOMS+"m9",
	"south" : ROOMS+"g30",
	]) );
}
