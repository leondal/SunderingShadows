#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g25",
	"east" : ROOMS+"g27",
	"north" : ROOMS+"g117",
	"south" : ROOMS+"g21",
	]) );
}
