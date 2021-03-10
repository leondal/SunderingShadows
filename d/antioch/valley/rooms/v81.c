#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v80",
	"west" : ROOMS+"g41",
	"north" : ROOMS+"g46",
	"south" : ROOMS+"v82",
	]) );
}
