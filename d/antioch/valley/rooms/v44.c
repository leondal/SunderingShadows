#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v45",
	"south" : ROOMS+"v43",
	"north" : ROOMS+"v50",
	"northwest" : ROOMS+"v51",
	"southwest" : ROOMS+"v42",
	]) );
}
