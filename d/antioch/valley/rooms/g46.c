#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g45",
	"east" : ROOMS+"v79",
	"north" : ROOMS+"g48",
	"south" : ROOMS+"v81",
	]) );
}
