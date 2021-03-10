#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g5",
	"east" : ROOMS+"g7",
	"north" : ROOMS+"g17",
	"south" : ROOMS+"v16",
	]) );
}
