#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g6",
	"east" : ROOMS+"g8",
	"north" : ROOMS+"g16",
	"south" : ROOMS+"v15",
	]) );
}
