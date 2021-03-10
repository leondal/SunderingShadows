#include <std.h>
#include "../antioch.h"
inherit GUEST;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_exits(([
	"south" : ROOMS+"pal9",
	]));
	set_door("fox door",ROOMS+"pal9","south",0);
	add_item("fox door","On the southern wall is a cedar wood door that"+
	" leads back out to the hallway. The image of a fox has been carved"+
	" into the center of the door.");
}
