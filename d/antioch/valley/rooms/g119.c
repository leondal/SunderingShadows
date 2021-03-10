#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g120",
	"east" : ROOMS+"g118",
	"north" : ROOMS+"g96",
	"south" : ROOMS+"g24",
	]) );
}
