#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g63",
	"east" : ROOMS+"m36",
	"north" : ROOMS+"v63",
	"south" : ROOMS+"m33",
	]) );
}
