#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"palace16",
	"south" : ROOMS+"palace18",
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
