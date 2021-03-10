#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g57",
	"east" : ROOMS+"g59",
	"north" : ROOMS+"v68",
	"south" : ROOMS+"g54",
	]) );
}
