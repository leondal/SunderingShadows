#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g33",
	"east" : ROOMS+"v87",
	"north" : ROOMS+"g36",
	"south" : ROOMS+"v89",
	]) );
}
