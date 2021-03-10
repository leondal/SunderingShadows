#include <std.h>
#include "../valley.h"
inherit WFLOWERS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"w3",
	"east" : ROOMS+"m18",
	"north" : ROOMS+"m25",
	"south" : ROOMS+"m13",
	]) );
}
