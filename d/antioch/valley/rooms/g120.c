#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g121",
	"east" : ROOMS+"g119",
	"north" : ROOMS+"g95",
	"south" : ROOMS+"g23",
	]) );
}
