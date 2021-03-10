#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m29",
	"east" : ROOMS+"g55",
	"north" : ROOMS+"g56",
	"south" : ROOMS+"m26",
	]) );
}
