#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g113",
	"east" : ROOMS+"m3",
	"north" : ROOMS+"m8",
	"south" : ROOMS+"g31",
	]) );
}
