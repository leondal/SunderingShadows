#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m36",
	"east" : ROOMS+"v66",
	"north" : ROOMS+"rb9",
	"south" : ROOMS+"m35",
	]) );
}
