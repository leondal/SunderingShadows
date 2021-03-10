#include <std.h>
#include "../valley.h"
inherit VALLEY;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"v76",
	"southeast" : ROOMS+"e2431",
	"northwest" : ROOMS+"v75",
	"southwest" : ROOMS+"v78",
	]) );
	set_invis_exits(({"southeast"}));
}
