#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"m26",
	"east" : ROOMS+"g53",
	"north" : ROOMS+"g55",
	"south" : ROOMS+"m17",
	]) );
}
