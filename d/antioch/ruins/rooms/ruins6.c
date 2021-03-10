#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(RUINS);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",1);
	set_short("%^BOLD%^%^BLACK%^Desolate Ruins%^RESET%^");
	set_long(
	"This used to be the old rations shop. To the west the roof has collapsed"+
	" and blocked off the rest of the shop. Boxes of food are scattered about"+
	" the room, but they have been ruined by the rain water that has leaked"+
	" in through the ruined roof. The counters are on the floor, most are"+
	" split in half or cracked. Mold has begun to grow around the room."
	);
	set_smell("default","The scent of spoiled food and mold fills the room.");
	set_listen("default","The wind whistles through the holes in the roof.");
	set_items(([
	"floor" : "The floor is covered in dirt, mud, and mold.",
	({"ceiling","roof"}) : "To the west the roof has collapsed upon the rest"+
	" of the shop. The one above your head is in rather bad shape, with"+
	" holes in it that let the rain through.",
	"mold" : "%^GREEN%^Mold is growing on the walls and floor, and especially"+
	" on the boxes of food that have been spoiled by the weather.",
	({"food","spoiled food","boxes","boxes of food"}) : "Boxes of spoil food"+
	" lay scattered about the floor. They have been nibbled on by rats, but"+
	" after they began to mold, not even the rats seemed to want them.",
	"counters" : "Counters lay broken and cracked across the floor.",
	]));
	set_exits(([
	"east" : ROOMS+"ruins5",
	]));
}
