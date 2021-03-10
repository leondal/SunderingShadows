#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m2",
	"east" : ROOMS+"m4",
	"north" : ROOMS+"m7",
	"south" : ROOMS+"m1",
	]) );
}
