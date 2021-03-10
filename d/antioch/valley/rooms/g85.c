#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^There is a large tree to the east.\n"
	);
	set("night long",query("night long")+"%^GREEN%^There is a large tree to the east.\n"
	);
	set_exits( ([
	"east" : ROOMS+"dryad1",
	"west" : ROOMS+"v37",
	"north" : ROOMS+"v40",
	"south" : ROOMS+"v35",
	]) );
}

