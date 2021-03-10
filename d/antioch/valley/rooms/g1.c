#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^There is a large tree to the north.\n"
	);
	set("night long",query("night long")+"%^GREEN%^There is a large tree to the north.\n"
	);
	set_exits( ([
	"west" : ROOMS+"v23",
	"east" : ROOMS+"g2",
	"south" : ROOMS+"v21",
	"north" : ROOMS+"dryad2",
	]) );
}
