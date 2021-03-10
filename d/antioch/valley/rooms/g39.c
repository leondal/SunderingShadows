#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g38",
	"east" : ROOMS+"g40",
	"north" : ROOMS+"g43",
	"south" : ROOMS+"g35",
	]) );
}
