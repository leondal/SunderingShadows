#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g58",
	"east" : ROOMS+"g60",
	"north" : ROOMS+"v69",
	"south" : ROOMS+"g51",
	]) );
}
