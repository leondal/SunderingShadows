#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"rb13",
	"east" : ROOMS+"rb15",
	"south" : ROOMS+"v70",
	]) );
}
