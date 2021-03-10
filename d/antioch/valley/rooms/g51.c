#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g54",
	"east" : ROOMS+"g50",
	"north" : ROOMS+"g59",
	"south" : ROOMS+"g52",
	]) );
}
