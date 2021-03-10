#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"g85",
	"west" : ROOMS+"v38",
	"south" : ROOMS+"v36",
	"north" : ROOMS+"v39",
	]) );
}
