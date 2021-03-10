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
	"This was once the main street through town, now it is interrupted in"+
	" places by cracks. The shops that were on either side of the street"+
	" here have collapsed, it looks as though earthquakes shook the city to"+
	" pieces. The streets are charred in places and wood from the shops has"+
	" fallen across the road in places. In the northern distance is a"+
	" crumbling tower."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	({"streets","street"}) : "The streets have large cracks running through"+
	" them, probably from earthquakes that appear to have shook the entire"+
	" area. Wood from the collapsed houses has fallen into the street in"+
	" places.",
	({"shop","shops"}) : "The shops on either side of the street have collapsed"+
	" into heaps of wood.",
	"tower" : "In the distance to the north is a large tower that has greatly"+
	" crumbled, now standing barely three stories tall.",
	]));
	set_exits(([
	"north" : ROOMS+"ruins9",
	"south" : ROOMS+"ruins5",
	]));
}

void reset()
{
	::reset();
	if(!present("monster")) {
		switch(random(5)) {
			case 0:
				new(MONS+"shadow")->move(TO);
				new(MONS+"shadow")->move(TO);
				break;
			case 1:
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				break;
			case 2:
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				break;
			case 3:
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				break;
			case 4:
				new(MONS+"shadow")->move(TO);
				new(MONS+"shadow")->move(TO);
				new(MONS+"shadow")->move(TO);
				break;
		}
	}
}
