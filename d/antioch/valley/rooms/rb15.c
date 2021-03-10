#include <std.h>
#include "../valley.h"
inherit RIVER1;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"rb14",
	"southeast" : ROOMS+"v72",
	"south" : ROOMS+"v71",
	]) );
}
