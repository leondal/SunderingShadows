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
	"west" : ROOMS+"g95",
	"east" : ROOMS+"g97",
	"south" : ROOMS+"g119",
	"north" : FRING+"f1",
	]) );
}
