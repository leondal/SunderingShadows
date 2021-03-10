#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v66",
	"east" : ROOMS+"v68",
	"north" : ROOMS+"rb11",
	"south" : ROOMS+"g57",
	]) );
}
