#include <std.h>
#include "../antioch.h"
inherit GUEST;

void create()
{
	::create();
	set_exits(([
	"north" : ROOMS+"pal10",
	]));
	set_door("wolf door",ROOMS+"pal10","north",0);
	add_item("wolf door","On the northern wall is a cedar wood door that"+
	" leads back out to the hallway. The image of a wolf has been carved"+
	" into the center of the door.");
}
