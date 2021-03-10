#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g60",
	"east" : ROOMS+"v73",
	"north" : ROOMS+"v71",
	"south" : ROOMS+"g49",
	]) );
}
