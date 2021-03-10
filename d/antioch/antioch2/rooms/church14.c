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
	" streets and shops. The north window overlooks the church and you can"+
	" see across to a guard tower that looks identical to this one. The"+
	" southern window shows some of the small shops and the large gates of"+
	" Antioch. The eastern window shows a view of the ruins of the old city"+
	" of Antioch and the new road that leads from it to the new city of Antioch."
	);
	set_smell("default","You smell the crisp, clean mountain air.");
	set_listen("default","The wind whistles slightly outside the window.");
	set_items(([
	"ceiling" : "The ceiling is made of stones and arches into a conical point"+
	" so that the roof slopes downwards and the rain water trickles off.",
	"floor" : "The stone floor looks cold and bare, but it is quite well swept.",
	"windows" : "There are four windows here that overlook the area around"+
	" Antioch.",
	({"west window","western window"}) : "The western window shows the shops"+
	" and streets of Antioch. You can see the healer's shop and the guards'"+
	" barracks quite easily from here.",
	({"east window","eastern window"}) : "The eastern window holds a view of"+
	" the ruins of the old Antioch city. It also shows the new path that now"+
	" leads to the city of Antioch. The path is small now, but slowly widening.",
	({"north window","northern window"}) : "Out the northern window you can"+
	" see the roof of the church. It is arched and tiled so that the water"+
	" easily slips off of it should it rain. You can also see a guard tower"+
	" identical to the one you're standing in.",
	({"south window","southern window"}) : "This window overlooks the large"+
	" gates of Antioch. You can see anyone who wishes to enter the gates of"+
	" the city from here.",
	]));
	set_exits(([
   "down" : ROOMS+"church9",
	]));
}
