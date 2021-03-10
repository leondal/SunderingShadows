#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g77",
	"east" : ROOMS+"g75",
	"north" : ROOMS+"g68",
	"south" : ROOMS+"g111",
	]) );
}
