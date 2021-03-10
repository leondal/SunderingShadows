#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the south you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the south you see a fairy ring.\n"
	);
	set_exits( ([
	"west" : ROOMS+"g81",
	"east" : ROOMS+"g79",
	"north" : ROOMS+"v46",
	"southwest" : ROOMS+"g82",
	]) );
}
