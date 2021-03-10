#include <std.h>
#include "../valley.h"
inherit VAL_2;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v68",
	"east" : ROOMS+"v70",
	"north" : ROOMS+"rb13",
	"south" : ROOMS+"g59",
	]) );
}
