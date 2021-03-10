#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g8",
	"east" : ROOMS+"g10",
	"north" : ROOMS+"g14",
	"south" : ROOMS+"v13",
	]) );
}
