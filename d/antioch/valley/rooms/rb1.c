#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"shore15",
	"east" : ROOMS+"rb2",
	"south" : ROOMS+"v60",
	]) );
}

void reset()
{
	::reset();
	if(query_night() != 1) {
		if(!present("swanmay")) {
			new(MONS+"swanmay")->move(TO);
		}
	}
}
