#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the east you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the east you see a fairy ring.\n"
	);
	set_exits( ([
	"west" : ROOMS+"g83",
	"north" : ROOMS+"g81",
	"south" : ROOMS+"g89",
	"northeast" : ROOMS+"g80",
	]) );
}
