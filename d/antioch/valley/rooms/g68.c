#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v49",
	"east" : ROOMS+"g69",
	"north" : ROOMS+"v53",
	"south" : ROOMS+"g76",
	]) );
}
