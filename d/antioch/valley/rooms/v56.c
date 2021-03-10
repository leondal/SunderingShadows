#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"shore12",
	"east" : ROOMS+"v57",
	"north" : ROOMS+"shore14",
	"northwest" : ROOMS+"shore13",
	"south" : ROOMS+"v55",
	]) );
}
