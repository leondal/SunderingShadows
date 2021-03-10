#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g110",
	"east" : ROOMS+"m22",
	"north" : ROOMS+"g74",
	"south" : ROOMS+"m21",
	]) );
}
