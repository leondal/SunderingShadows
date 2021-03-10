#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g87",
	"east" : ROOMS+"g89",
	"north" : ROOMS+"g83",
	"south" : ROOMS+"g91",
	]) );
}
