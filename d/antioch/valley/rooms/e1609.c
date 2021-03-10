#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e1708",
	"north" : ROOMS+"e1709",
	]) );
	set_invis_exits(({"northwest","north"}));
}

