#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g43",
	"east" : ROOMS+"g41",
	"north" : ROOMS+"g44",
	"south" : ROOMS+"g40",
	]) );
}
