#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the southwest you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the southwest you see a fairy ring.\n"
	);
	set_exits( ([
	"west" : ROOMS+"g78",
	"east" : ROOMS+"g76",
	"north" : ROOMS+"v49",
	"south" : ROOMS+"g112",
	]) );
}
