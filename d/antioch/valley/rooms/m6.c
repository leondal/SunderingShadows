#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m7",
	"east" : ROOMS+"m5",
	"north" : ROOMS+"m13",
	"south" : ROOMS+"m4",
	]) );
}
