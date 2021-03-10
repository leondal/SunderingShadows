#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v40",
	"east" : ROOMS+"v42",
	"south" : ROOMS+"dryad1",
	"north" : ROOMS+"e2706",
	]) );
	set_invis_exits(({"north"}));
}
