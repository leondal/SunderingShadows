#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"south" : ROOMS+"v80",
	"east" : ROOMS+"v78",
	"west" : ROOMS+"g46",
	"north" : ROOMS+"g47",
	]) );
}
