#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m17",
	"east" : ROOMS+"g44",
	"north" : ROOMS+"g53",
	"south" : ROOMS+"g43",
	]) );
}
