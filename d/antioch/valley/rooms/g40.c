#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g39",
	"east" : ROOMS+"v83",
	"north" : ROOMS+"g42",
	"south" : ROOMS+"v85",
	]) );
}
