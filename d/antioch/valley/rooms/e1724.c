#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e1723",
	"north" : ROOMS+"e1824",
	]) );
	set_invis_exits(({"north","west"}));
}
