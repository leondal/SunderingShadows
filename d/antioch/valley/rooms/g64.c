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
	"west" : ROOMS+"dryad4",
	"east" : ROOMS+"g63",
	"north" : ROOMS+"g65",
	"south" : ROOMS+"g71",
	]) );
}
