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
	"east" : ROOMS+"dryad5",
	"west" : ROOMS+"g28",
	"north" : ROOMS+"g115",
	"south" : ROOMS+"g18",
	]) );
}

