#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g74",
	"east" : ROOMS+"m32",
	"north" : ROOMS+"g71",
	"south" : ROOMS+"m22",
	]) );
}
