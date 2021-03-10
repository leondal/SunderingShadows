#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"w5",
	"east" : ROOMS+"m26",
	"north" : ROOMS+"m29",
	"south" : ROOMS+"w4",
	]) );
}
