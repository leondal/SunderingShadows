#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v62",
	"east" : ROOMS+"v64",
	"north" : ROOMS+"rb6",
	"south" : ROOMS+"g62",
	]) );
}
