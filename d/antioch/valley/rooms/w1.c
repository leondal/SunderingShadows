#include <std.h>
#include "../valley.h"
inherit WFLOWERS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m12",
	"east" : ROOMS+"m13",
	"north" : ROOMS+"w3",
	"south" : ROOMS+"m7",
	]) );
}
