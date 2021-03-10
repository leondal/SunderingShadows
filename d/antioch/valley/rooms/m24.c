#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m23",
	"east" : ROOMS+"w5",
	"north" : ROOMS+"m31",
	"south" : ROOMS+"w2",
	]) );
}
