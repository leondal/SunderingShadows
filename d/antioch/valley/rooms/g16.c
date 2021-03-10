#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g17",
	"east" : ROOMS+"g15",
	"north" : ROOMS+"g30",
	"south" : ROOMS+"g7",
	]) );
}
