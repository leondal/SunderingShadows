#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"rb12",
	"east" : ROOMS+"rb14",
	"south" : ROOMS+"v69",
	]) );
}
