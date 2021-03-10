#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m34",
	"east" : ROOMS+"g56",
	"north" : ROOMS+"v65",
	"south" : ROOMS+"m29",
	]) );
}
