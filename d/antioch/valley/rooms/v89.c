#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g12",
	"east" : ROOMS+"v88",
	"north" : ROOMS+"g34",
	"south" : ROOMS+"v90",
	]) );
}
