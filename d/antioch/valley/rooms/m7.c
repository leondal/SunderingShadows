#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m8",
	"east" : ROOMS+"m6",
	"north" : ROOMS+"w1",
	"south" : ROOMS+"m3",
	]) );
}
