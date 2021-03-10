#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v63",
	"east" : ROOMS+"rb9",
	"southeast" : ROOMS+"v65",
	"south" : ROOMS+"m36",
	"north" : ROOMS+"rb7",
	]) );
}
