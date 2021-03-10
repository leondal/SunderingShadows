#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g112",
	"east" : ROOMS+"g110",
	"north" : ROOMS+"g76",
	"south" : ROOMS+"g107",
	]) );
}
