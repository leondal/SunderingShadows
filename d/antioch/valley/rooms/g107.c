#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g106",
	"east" : ROOMS+"g108",
	"north" : ROOMS+"g111",
	"south" : ROOMS+"g104",
	]) );
}
