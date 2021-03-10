#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g59",
	"east" : ROOMS+"g61",
	"north" : ROOMS+"v70",
	"south" : ROOMS+"g50",
	]) );
}
