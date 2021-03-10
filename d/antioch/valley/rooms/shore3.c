#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"north" : ROOMS+"shore2",
	"south" : ROOMS+"shore16",
	"southeast" : ROOMS+"shore4",
	]) );
}
