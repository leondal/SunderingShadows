#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"rb9",
	"east" : ROOMS+"rb11",
	"south" : ROOMS+"v66",
	"northwest" : ROOMS+"rb8",
	]) );
}
