#include <std.h>
#include "../valley.h"
inherit C_SHORE1;

void create()
{
	::create();
	set_exits( ([
	"south" : ROOMS+"shore2",
	"north" : ROOMS+"cliff",
	]) );
}
