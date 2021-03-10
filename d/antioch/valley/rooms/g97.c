#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^To the north you see a fairy ring.\n"
	);
	set("night long",query("night long")+"%^GREEN%^To the north you see a fairy ring.\n"
	);
	set_exits( ([
	"west" : ROOMS+"g96",
	"east" : ROOMS+"g98",
	"south" : ROOMS+"g118",
	"northeast" : ROOMS+"g105",
	]) );
}
