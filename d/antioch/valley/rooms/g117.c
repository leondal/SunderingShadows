#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g118",
	"east" : ROOMS+"snake",
	"north" : ROOMS+"g98",
	"south" : ROOMS+"g26",
	]) );
}
