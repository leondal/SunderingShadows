#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"rb10",
	"east" : ROOMS+"rb12",
	"south" : ROOMS+"v67",
	]) );
}
