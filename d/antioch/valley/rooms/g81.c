#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the southeast you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the southeast you see a fairy ring.\n"
	);
	set_exits( ([
	"west" : ROOMS+"v43",
	"east" : ROOMS+"g80",
	"north" : ROOMS+"v45",
	"south" : ROOMS+"g82",
	]) );
}
