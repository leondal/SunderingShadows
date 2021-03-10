#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g14",
	"east" : ROOMS+"g12",
	"north" : ROOMS+"g32",
	"south" : ROOMS+"g10",
	]) );
}
