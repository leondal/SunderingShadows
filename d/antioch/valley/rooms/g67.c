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
	"east" : ROOMS+"dryad4",
	"west" : ROOMS+"v53",
	"north" : ROOMS+"v55",
	"south" : ROOMS+"g69",
	]) );
}

