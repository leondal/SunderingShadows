#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m20",
	"east" : ROOMS+"w2",
	"north" : ROOMS+"m23",
	"south" : ROOMS+"m11",
	]) );
}
