#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m27",
	"east" : ROOMS+"g52",
	"north" : ROOMS+"g54",
	"south" : ROOMS+"m16",
	]) );
}
