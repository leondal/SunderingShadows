#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g32",
	"east" : ROOMS+"g34",
	"north" : ROOMS+"g37",
	"south" : ROOMS+"g12",
	]) );
}
