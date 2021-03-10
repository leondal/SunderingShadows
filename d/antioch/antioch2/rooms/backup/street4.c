#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Pine Street");
	set_long(
	"You are on Pine street. \n"+
	"Further to the northwest you can"+
	" see it intersects with Apple street. To the southeast is"+
	" the intersection with Crescent street. There is also a"+
	" a leather shop there, and it leads to the Healer and the"+
	" guard tower. You smell the faint scent of a stables and"+
	" can hear the sound of horses up to the northwest. The"+
	" smell of leather is also still in the air."
	);
	set("night long",
	"You are on Pine street.\n"+
	"Up to the northwest is the intersection of Pine and Apple."+
	" To the southeast Pine intersects with Crescent. There is"+
	" a leather shop close to the south, and further that way"+
	" you can find the Healer and the guard tower. A street light"+
	" shines warm light on the area, keeping things fairly well"+
	" lit."
	);
	set_smell("default","There is a faint scent of leather mixed"+
	" with the smell of a stable on the breeze.");
	set_listen("default","You hear the faint sound of horses"+
	" in the distance.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is Pine street.",
	]));
	set_exits(([
	"northwest" : ROOMS+"street5",
	"southeast" : ROOMS+"street3",
	]));
}

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
}
