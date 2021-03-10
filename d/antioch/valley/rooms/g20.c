#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g21",
	"east" : ROOMS+"g19",
	"north" : ROOMS+"g27",
	"south" : ROOMS+"g3",
	]) );
}
