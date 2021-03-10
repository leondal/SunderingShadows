#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"north" : ROOMS+"e2228",
	"east" : ROOMS+"e2129",
	]) );
	set_invis_exits(({"north","east"}));
}

