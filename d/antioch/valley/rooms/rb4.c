#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"v61",
	"east" : ROOMS+"rb5",
	"south" : ROOMS+"v63",
	"north" : ROOMS+"rb3",
	"southwest" : ROOMS+"v58",
	]) );
}
