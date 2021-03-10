#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"e1524",
	]) );
	set_invis_exits(({"west"}));
}
