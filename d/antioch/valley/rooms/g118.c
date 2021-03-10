#include <std.h>
#include "../valley.h"
inherit GRASS1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g119",
	"east" : ROOMS+"g117",
	"north" : ROOMS+"g97",
	"south" : ROOMS+"g25",
	]) );
}
