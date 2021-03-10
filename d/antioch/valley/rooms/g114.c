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
	"south" : ROOMS+"dryad5",
	"north" : ROOMS+"m9",
	"west" : ROOMS+"g115",
	"east" : ROOMS+"g113",
	]) );
}

