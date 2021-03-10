#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^There is a large tree to the west.\n"
	);
	set("night long",query("night long")+"%^GREEN%^There is a large tree to the west.\n"
	);
	set_exits( ([
	"west" : ROOMS+"dryad6",
	"east" : ROOMS+"g47",
	"north" : ROOMS+"g49",
	"south" : ROOMS+"g46",
	]) );
}
