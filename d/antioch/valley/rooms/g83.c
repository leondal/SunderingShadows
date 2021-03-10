#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g84",
	"east" : ROOMS+"g82",
	"north" : ROOMS+"v43",
	"south" : ROOMS+"g88",
	]) );
}
