#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v69",
	"east" : ROOMS+"v71",
	"north" : ROOMS+"rb14",
	"south" : ROOMS+"g60",
	]) );
}
