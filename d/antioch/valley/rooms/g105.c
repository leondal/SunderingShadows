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
	"east" : ROOMS+"g104",
	"north" : ROOMS+"g106",
	"south" : ROOMS+"g98",
	"southwest" : ROOMS+"g97",
	]) );
}
