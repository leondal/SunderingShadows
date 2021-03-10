#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m33",
	"east" : ROOMS+"m35",
	"north" : ROOMS+"m36",
	"south" : ROOMS+"m30",
	]) );
}
