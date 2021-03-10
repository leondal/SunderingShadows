#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m30",
	"east" : ROOMS+"m28",
	"north" : ROOMS+"m35",
	"south" : ROOMS+"m25",
	]) );
}
