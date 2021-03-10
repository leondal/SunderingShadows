#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v33",
	"east" : ROOMS+"g91",
	"north" : ROOMS+"g87",
	"south" : ROOMS+"v31",
	]) );
}
