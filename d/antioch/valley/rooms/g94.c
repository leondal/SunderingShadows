#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the northeast you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the northeast you see a fairy ring.\n"
	);
	set_exits( ([
	"west" : ROOMS+"g93",
	"east" : ROOMS+"g95",
	"south" : ROOMS+"g121",
	"north" : ROOMS+"g92",
	]) );
}
