#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m3",
	"east" : ROOMS+"g37",
	"north" : ROOMS+"m6",
	"south" : ROOMS+"g32",
	]) );
}
