#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g48",
	"east" : ROOMS+"v76",
	"north" : ROOMS+"v74",
	"south" : ROOMS+"v79",
	]) );
}
