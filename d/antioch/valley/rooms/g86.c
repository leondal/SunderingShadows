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
	"north" : ROOMS+"dryad1",
	"south" : ROOMS+"v33",
	"west" : ROOMS+"v35",
	"east" : ROOMS+"g87",
	]) );
}

