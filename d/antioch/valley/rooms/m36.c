#include <std.h>
#include "../valley.h"
inherit MEADOW;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g62",
	"east" : ROOMS+"v65",
	"north" : ROOMS+"v64",
	"south" : ROOMS+"m34",
	]) );
}
