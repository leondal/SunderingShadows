#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g26",
	"east" : ROOMS+"g28",
	"north" : ROOMS+"snake",
	"south" : ROOMS+"g20",
	]) );
}
