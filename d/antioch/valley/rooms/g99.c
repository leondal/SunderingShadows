#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g98",
	"east" : ROOMS+"g100",
	"north" : ROOMS+"g104",
	"south" : ROOMS+"snake",
	]) );
}
