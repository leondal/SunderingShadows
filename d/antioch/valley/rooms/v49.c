#include <std.h>
#include "../valley.h"
inherit VALLEY1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v48",
	"east" : ROOMS+"g68",
	"north" : ROOMS+"v52",
	"northwest" : ROOMS+"shore8",
	"south" : ROOMS+"g77",
	]) );
}
