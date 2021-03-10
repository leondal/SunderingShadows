#include <std.h>
#include "../valley.h"
inherit VAL_2;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v70",
	"east" : ROOMS+"v72",
	"north" : ROOMS+"rb15",
	"south" : ROOMS+"g61",
	]) );
}
