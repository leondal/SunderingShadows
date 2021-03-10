#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"rb4",
	"southeast" : ROOMS+"rb7",
	"south" : ROOMS+"rb6",
	"southwest" : ROOMS+"v59",
   "northwest" : ROOMS+"rb3",
	]) );
}
