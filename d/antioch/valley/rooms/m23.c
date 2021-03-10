#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m22",
	"east" : ROOMS+"m24",
	"north" : ROOMS+"m32",
	"south" : ROOMS+"m19",
	]) );
}
