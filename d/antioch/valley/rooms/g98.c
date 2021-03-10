#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the northwest you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the northwest you see a fairy ring.\n"
	);
	set_exits( ([
	"west" : ROOMS+"g97",
	"east" : ROOMS+"g99",
	"south" : ROOMS+"g117",
	"north" : ROOMS+"g105",
	]) );
}
