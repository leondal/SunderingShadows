#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m25",
	"east" : ROOMS+"m27",
	"north" : ROOMS+"m28",
	"south" : ROOMS+"m18",
	]) );
}
