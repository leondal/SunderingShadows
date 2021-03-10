#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^There is a large tree to the south.\n"
	);
	set("night long",query("night long")+"%^GREEN%^There is a large tree to the south.\n"
	);
	set_exits( ([
	"south" : ROOMS+"dryad6",
	"north" : ROOMS+"g60",
	"west" : ROOMS+"g51",
	"east" : ROOMS+"g49",
	]) );
}

