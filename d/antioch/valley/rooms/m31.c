#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m32",
	"east" : ROOMS+"m30",
	"north" : ROOMS+"m33",
	"south" : ROOMS+"m24",
	]) );
}
