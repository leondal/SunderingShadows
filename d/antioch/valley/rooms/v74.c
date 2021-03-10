#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g49",
	"east" : ROOMS+"v75",
	"north" : ROOMS+"v73",
	"south" : ROOMS+"g47",
	]) );
}
