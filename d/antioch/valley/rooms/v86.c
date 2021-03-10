#include <std.h>
#include "../valley.h"
inherit VAL_1;

void create()
{
	::create();
	set_exits( ([
	"northeast" : ROOMS+"v84",
	"southwest" : ROOMS+"v88",
	"north" : ROOMS+"v85",
	"west" : ROOMS+"v87",
	"southeast" : ROOMS+"e1926",
	]) );
	set_invis_exits(({"southeast"}));
}
