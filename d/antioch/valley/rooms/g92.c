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
	"west" : ROOMS+"g91",
	"north" : ROOMS+"g89",
	"south" : ROOMS+"g94",
	"southeast" : ROOMS+"g95",
	]) );
}
