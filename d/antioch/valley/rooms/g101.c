#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g100",
	"east" : ROOMS+"g102",
	"north" : ROOMS+"g103",
	"south" : ROOMS+"g115",
	]) );
}
