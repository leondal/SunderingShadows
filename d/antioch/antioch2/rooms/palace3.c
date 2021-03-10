#include <std.h>
#include "../antioch.h"
inherit PALACE;

void create()
{
	::create();
	set_exits(([
	"west" : ROOMS+"palace2",
	"east" : ROOMS+"palace4",
	]));
   new(MONS+"captain")->move(TO);
}
