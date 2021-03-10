#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g16",
	"east" : ROOMS+"g14",
	"north" : ROOMS+"g31",
	"south" : ROOMS+"g8",
	]) );
}
