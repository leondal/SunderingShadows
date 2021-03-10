#include <std.h>
#include "../antioch.h"
inherit GUEST;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_exits(([
	"north" : ROOMS+"pal9",
	]));
	set_door("hawk door",ROOMS+"pal9","north",0);
	add_item("hawk door","On the northern wall is a cedar wood door that"+
	" leads back out to the hallway. The image of a hawk has been carved"+
	" into the center of the door.");
}
