#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v27",
	"east" : ROOMS+"g24",
	"north" : ROOMS+"g120",
	"south" : ROOMS+"v25",
	]) );
}
