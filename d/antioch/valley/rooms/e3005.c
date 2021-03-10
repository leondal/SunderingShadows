#include <std.h>
#include "../valley.h"
inherit EDGE2;

void create()
{
	::create();
	set_exits( ([
	"south" : ROOMS+"e2905",
	"east" : ROOMS+"e3006",
	]) );
	set_invis_exits(({"south","east"}));
}

void reset()
{
	::reset();
	if(!present("creeper")) {
		if(!random(2)) {
			new(MONS+"creeper")->move(TO);
		}
	}
}
