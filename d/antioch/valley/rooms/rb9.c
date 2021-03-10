#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"v64",
	"east" : ROOMS+"rb10",
	"south" : ROOMS+"v65",
	"northwest" : ROOMS+"rb7",
	"north" : ROOMS+"rb8",
	]) );
}
