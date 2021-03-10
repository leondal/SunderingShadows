#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"rb1",
	"east" : ROOMS+"rb3",
	"south" : ROOMS+"v61",
	]) );
}
