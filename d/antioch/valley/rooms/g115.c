#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g116",
	"east" : ROOMS+"g114",
	"north" : ROOMS+"g101",
	"south" : ROOMS+"g29",
	]) );
}
