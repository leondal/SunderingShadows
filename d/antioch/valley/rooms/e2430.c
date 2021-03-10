#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v78",
	"southwest" : ROOMS+"e2329",
	"east" : ROOMS+"e2431",
	]) );
	set_invis_exits(({"southwest","west","east"}));
}

