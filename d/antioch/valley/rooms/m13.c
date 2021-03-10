#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"w1",
	"east" : ROOMS+"m14",
	"north" : ROOMS+"w4",
	"south" : ROOMS+"m6",
	]) );
}
