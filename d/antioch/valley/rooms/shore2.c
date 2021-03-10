#include <std.h>
#include "../valley.h"
inherit C_SHORE;

void create()
{
	::create();
   set_exits( ([
	"north" : ROOMS+"shore1",
	"south" : ROOMS+"shore3",
	]) );
}
