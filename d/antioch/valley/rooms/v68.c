#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v67",
	"east" : ROOMS+"v69",
	"north" : ROOMS+"rb12",
	"south" : ROOMS+"g58",
	]) );
}
