#include <std.h>
#include "../valley.h"
inherit WFLOWERS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m19",
	"east" : ROOMS+"w3",
	"north" : ROOMS+"m24",
	"south" : ROOMS+"m12",
	]) );
}
