#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g86",
	"east" : ROOMS+"g88",
	"north" : ROOMS+"g84",
	"south" : ROOMS+"g90",
	]) );
}
