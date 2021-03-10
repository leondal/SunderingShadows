#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the west you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the west you see a fairy ring.\n"
	);
	set_exits( ([
	"east" : ROOMS+"g111",
	"north" : ROOMS+"g77",
	"south" : ROOMS+"g106",
	"northwest" : ROOMS+"g78",
	]) );
}
