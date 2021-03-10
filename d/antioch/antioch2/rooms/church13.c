#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Third floor of Antioch's Grand Church");
	set_long(
	"The spiral stair case winds up to this small chamber. The small room is"+
	" completely bare. The ceiling ends in an arched roof that comes to a"+
	" conical point.The room is more like a watch tower, really, with windows"+
	" on every side to over look the city. The western window overlooks the"+
	" streets and shops. The north window shows a view of some of the shops"+
	" along with the inn and the palace. The southern window shows the church"+
	" and another watch tower. The eastern window shows a view of the ruins"+
	" of the old city of Antioch and a large cemetary with many tombstones of"+
	" the good citizens who died during those tragic times of darkness."
	);
	set_smell("default","You smell the crisp, clean mountain air.");
	set_listen("default","The wind whistles slightly outside the window.");
	set_items(([
	"ceiling" : "The ceiling is made of stones and arches into a conical point"+
	" so that the roof slopes downwards and the rain water trickles off.",
	"floor" : "The stone floor looks cold and bare, but it is quite well swept.",
	"windows" : "There are four windows here that overlook the area around"+
	" Antioch.",
	({"west window","western window"}) : "The western window shows a view of"+
	" many of the streets of Antioch, along with the shops. You can see the"+
	" stables across the streets and all the shops inbetween, including the"+
	" beautiful fountain. It is a peaceful scene.",
	({"east window","eastern window"}) : "The eastern window does not show a"+
	" pleasant view at all. It is the ruins of the first city of Antioch."+
	" The large tower that once stood so proudly is partially blasted and"+
	" crumbling. The entire area holds a dark and ominous quality to it. The"+
	" large cemetary tells of the many who died during the struggle against"+
	" darkness.",
	({"north window","northern window"}) : "The northern window shows some of"+
	" the smaller shops, along with the inn and a view of the palace. Beyond"+
	" the palace are the peaks of the Charu Mountains. Everything seems to be"+
	" peaceful.",
	({"south window","southern window"}) : "Out the southern window you can"+
	" see the middle section of the church. An arched tiled roof allows the"+
	" water to slide easily off of it. Directly across from here is another"+
	" guard tower that looks identical to this one.",
	]));
	set_exits(([
	"down" : ROOMS+"church7",
	]));
}
