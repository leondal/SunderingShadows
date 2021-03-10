#include <std.h>
#include "../valley.h"
inherit VAL_2;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v46",
	"east" : ROOMS+"v48",
	"north" : ROOMS+"shore7",
	"south" : ROOMS+"g79",
	]) );
}
