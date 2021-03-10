#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"south" : ROOMS+"e1825",
	]) );
	set_invis_exits(({"south"}));
}
