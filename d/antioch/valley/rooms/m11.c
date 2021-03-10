#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m10",
	"east" : ROOMS+"m12",
	"north" : ROOMS+"m19",
	"south" : ROOMS+"m9",
	]) );
}
