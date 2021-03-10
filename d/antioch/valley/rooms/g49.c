#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g50",
	"east" : ROOMS+"v74",
	"north" : ROOMS+"g61",
	"south" : ROOMS+"g48",
	]) );
}
