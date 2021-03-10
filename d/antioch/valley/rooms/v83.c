#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g40",
	"east" : ROOMS+"v82",
	"north" : ROOMS+"g41",
	"south" : ROOMS+"v84",
	]) );
}
