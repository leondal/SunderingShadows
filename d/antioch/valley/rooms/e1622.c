#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v10",
	"southeast" : ROOMS+"e1523",
	"north" : ROOMS+"v11",
	"east" : ROOMS+"e1623",
	]) );
	set_invis_exits(({"west","east","north","southeast"}));
}
