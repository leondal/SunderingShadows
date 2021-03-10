#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g102",
	"east" : ROOMS+"m8",
	"north" : ROOMS+"m11",
	"south" : ROOMS+"g113",
	]) );
}
