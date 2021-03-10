#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"rb5",
	"north" : ROOMS+"rb4",
	"east" : ROOMS+"rb6",
	"south" : ROOMS+"v62",
	"west" : ROOMS+"v58",
	]) );
}
