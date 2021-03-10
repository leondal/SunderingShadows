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
	"east" : ROOMS+"g107",
	"north" : ROOMS+"g112",
	"south" : ROOMS+"g105",
	]) );
}
