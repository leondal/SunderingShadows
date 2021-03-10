#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"south" : ROOMS+"palace16",
	"east" : ROOMS+"palace14",
	]));
}

void reset()
{
	::reset();
   if(!present("royal guard")) {
      new(MONS+"royal_guard")->move(TO);
   }
   return;
}
