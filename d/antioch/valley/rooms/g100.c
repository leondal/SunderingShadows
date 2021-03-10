#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^There is a large tree to the north.\n"
	);
	set("night long",query("night long")+"There is a large tree to the north.\n"
	);
	set_exits( ([
	"north" : ROOMS+"dryad3",
	"south" : ROOMS+"g116",
	"west" : ROOMS+"g99",
	"east" : ROOMS+"g101",
	]) );
}

