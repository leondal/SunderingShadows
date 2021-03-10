#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"palace9",
	"south" : ROOMS+"palace7",
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
