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
	"east" : ROOMS+"dryad6",
	"west" : ROOMS+"g53",
	"north" : ROOMS+"g51",
	"south" : ROOMS+"g44",
	]) );
}

