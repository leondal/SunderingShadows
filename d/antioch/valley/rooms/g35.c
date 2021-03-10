#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g36",
	"east" : ROOMS+"v85",
	"north" : ROOMS+"g39",
	"south" : ROOMS+"v87",
	]) );
}
