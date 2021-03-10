#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"snake",
	"east" : ROOMS+"g115",
	"north" : ROOMS+"g100",
	"south" : ROOMS+"g28",
	]) );
}
