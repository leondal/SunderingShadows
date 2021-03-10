#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"v59",
	"east" : ROOMS+"rb7",
	"south" : ROOMS+"v63",
	"north" : ROOMS+"rb5",
	"southwest" : ROOMS+"v62",
	]) );
}
