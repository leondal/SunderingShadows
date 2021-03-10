#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m16",
	"east" : ROOMS+"g45",
	"north" : ROOMS+"g52",
	"south" : ROOMS+"g42",
	]) );
}
