#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(RUINS);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",1);
	set_short("%^BOLD%^%^BLACK%^Desolate Ruins%^RESET%^");
	set_long(
	"The street is ended rather suddenly by the collapsed guard tower. Steps"+
	" that used to lead up into it end in mid air. The stones that used to"+
	" make up the large wall that surrounded the city have also fallen into"+
	" the street, cracking the road in places. Parts of the tower have been"+
	" blasted away, scorched stone is left around the missing chunks. A"+
	" mighty battle must have taken place here."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	"steps" : "Steps that used to lead up into the tower simply end in mid"+
	" air now.",
	"tower" : "The tower has collapsed to the east, causing the street to"+
	" come to an abrupt halt. The tower has been blasted in places, huge"+
	" chunks are missing and the surrounding areas are black with scorch"+
	" marks.",
	({"streets","street"}) : "The street is littered with stones"+
	" that have crashed to the ground when the great wall fell. There"+
	" are also charred sections from mage fire that was directed, or"+
	" reflected, here. The street has also been cracked in places where the"+
	" stones from the wall have crashed into it.",
	({"stones","wall","walls","stone"}) : "The walls around the city"+
	" have crumbled, the stones have crashed down into the streets."+
	" You would not have wanted to be here when the stone walls fell.",
	]));
	set_exits(([
	"west" : ROOMS+"fountain",
	]));
}
