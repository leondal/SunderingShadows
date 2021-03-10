#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Second floor of a Grand Church");
	set_long(
	"You are at the top of a stair case on the second floor of Antioch's"+
	" Grand Church. The stair case continues to spiral upwards out of"+
	" sight. On the eastern wall is a plain wooden door. It is engraved"+
	" with the symbol of a novice acolyte. A thin rug covers the"+
	" hallway here, leading to the south. You can see two more doors"+
	" along the length of the hallway and at the end another set of"+
	" stairs. Oil lamps hang from the ceiling in intervals, giving"+
	" light to the hallway. Incense holders are spaced out on the"+
	" western walls, they bring a scent of spiced apples."
	);
	set_smell("default","The room smells deliciously of spiced apples.");
	set_listen("default","It is peacefully quiet here.");
	set_items(([
	({"rug","thin rug","floor"}) : "A thin rug stretches down the length of"+
	" the hallway. It is decorated in concentric rectangular shapes"+
	" of multiple colors and is kept very clean.",
	({"lamp","lamps","oil lamp","oil lamps"}) : "Oil lamps hang from"+
	" small metal circles that are placed in the ceiling at intervals"+
	" all the way down the hallway, giving light to the place.",
	"incense" : "Sticks of incense are placed in holders on the western"+
	" wall. They are a rich cinammon color and smell of of spiced"+
	" apples.",
	"ceiling" : "Metal circles are placed at intervals along the"+
	" ceiling and oil lamps hang from them.",
	({"incense holder","incense holders"}) : "Pewter incense holders"+
	" are placed at intervals along the western wall.",
	({"stairs","stone stairs","stair case","staircase"}) : "The large"+
	" stone stair case here leads down to the first level as well as"+
	" spiraling up to at least another level. It is made out of large"+
	" stone blocks that look very sturdy.",
	"door" : "There is a plain wooden door on the eastern wall here."+
	" It is engraved with the symbol of a novice acolyte.",
	]));
	set_exits(([
	"down" : ROOMS+"church3",
	"south" : ROOMS+"church8",
	"up" : ROOMS+"church13",
	"east" : ROOMS+"church12",
	]));
	set_door("door",ROOMS+"church12","east",0);
}
