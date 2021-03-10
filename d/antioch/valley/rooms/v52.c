#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"shore8",
	"east" : ROOMS+"v53",
	"south" : ROOMS+"v49",
	"north" : ROOMS+"shore10",
	"northwest" : ROOMS+"shore9",
	]) );
}
