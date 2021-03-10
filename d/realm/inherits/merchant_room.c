#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit ROOM;

void create() 
{
	int x;
	object tmp;
 	::create();
	set_property("light", 1);
	set_property("indoors", 1);
	set_property("no teleport", 1);
	set_short("Gimpy's Supply Room");
	set_long("You shouldn't see this... ever - Saide.");
	x = 5 + random(3);	
	while(x)
	{
		x--;
		tmp = new("/d/common/obj/potion/advanced_heal");
		tmp->move(TO);
		tmp->set_uses(10 + random(6));
	}	
}

