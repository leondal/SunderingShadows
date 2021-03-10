#include <std.h>
#include "../valley.h"
inherit WFLOWERS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m24",
	"east" : ROOMS+"m25",
	"north" : ROOMS+"m30",
	"south" : ROOMS+"w3",
	]) );
}
