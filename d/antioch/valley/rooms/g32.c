#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m1",
	"east" : ROOMS+"g33",
	"north" : ROOMS+"m4",
	"south" : ROOMS+"g13",
	]) );
}
