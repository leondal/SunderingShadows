#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g55",
	"east" : ROOMS+"g51",
	"north" : ROOMS+"g58",
	"south" : ROOMS+"g53",
	]) );
}
