#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"w4",
	"east" : ROOMS+"m17",
	"north" : ROOMS+"m26",
	"south" : ROOMS+"m14",
	]) );
}
