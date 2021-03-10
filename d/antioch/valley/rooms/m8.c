#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m9",
	"east" : ROOMS+"m7",
	"north" : ROOMS+"m12",
	"south" : ROOMS+"m2",
	]) );
}
