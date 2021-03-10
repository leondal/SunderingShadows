#include <std.h>
#include "../valley.h"
inherit RIVER1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"rb6",
	"east" : ROOMS+"rb8",
	"south" : ROOMS+"v64",
	"southeast" : ROOMS+"rb9",
	"northwest" : ROOMS+"rb5",
	]) );
}
