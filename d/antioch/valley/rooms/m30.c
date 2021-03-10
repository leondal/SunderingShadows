#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m31",
	"east" : ROOMS+"m29",
	"north" : ROOMS+"m34",
	"south" : ROOMS+"w5",
	]) );
}
