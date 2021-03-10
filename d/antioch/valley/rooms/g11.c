#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g10",
	"east" : ROOMS+"v90",
	"north" : ROOMS+"g12",
	"south" : ROOMS+"v11",
	]) );
}
