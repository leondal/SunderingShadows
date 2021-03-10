#include <std.h>
#include "../valley.h"
inherit RIVER1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"rb11",
	"east" : ROOMS+"rb13",
	"south" : ROOMS+"v68",
	]) );
}
