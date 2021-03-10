#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m35",
	"east" : ROOMS+"g57",
	"north" : ROOMS+"v66",
	"south" : ROOMS+"m28",
	]) );
}
