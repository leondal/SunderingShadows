#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"shore10",
	"northwest" : ROOMS+"shore11",
	"east" : ROOMS+"v55",
	"south" : ROOMS+"v53",
	"north" : ROOMS+"shore11",
	]) );
}
