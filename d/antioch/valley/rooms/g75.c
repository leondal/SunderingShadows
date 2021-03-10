#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g76",
	"east" : ROOMS+"g74",
	"north" : ROOMS+"g69",
	"south" : ROOMS+"g110",
	]) );
}
