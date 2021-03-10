#include <std.h>
#include "../valley.h"
inherit MEADOW1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g31",
	"east" : ROOMS+"g32",
	"north" : ROOMS+"m3",
	"south" : ROOMS+"g14",
	]) );
}
