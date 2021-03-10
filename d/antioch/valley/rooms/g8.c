#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g7",
	"east" : ROOMS+"g9",
	"north" : ROOMS+"g15",
	"south" : ROOMS+"v14",
	]) );
}
