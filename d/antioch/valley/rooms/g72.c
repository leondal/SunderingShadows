#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g71",
	"east" : ROOMS+"m33",
	"north" : ROOMS+"g63",
	"south" : ROOMS+"m32",
	]) );
}
