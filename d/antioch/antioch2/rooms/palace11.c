#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"west" : ROOMS+"palace12",
	"south" : ROOMS+"palace10",
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
