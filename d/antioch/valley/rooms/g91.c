#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g90",
	"east" : ROOMS+"g92",
	"north" : ROOMS+"g88",
	"south" : ROOMS+"g93",
	]) );
}
