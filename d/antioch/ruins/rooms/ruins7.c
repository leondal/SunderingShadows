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
	"You are standing in the ruins of a small temple. The rest of the temple"+
	" to the east has collapsed. Broken statues of different gods litter"+
	" the floor here. A few religious symbols still hang precariously from"+
	" the walls, but most have fallen to the ground and shattered. Not even"+
	" the gods protected this place."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","Silence fills the temple.");
	set_items(([
	({"floor","ground"}) : "The ground is scattered with stone rubble from"+
	" the collapsed part of the temple to the east. Broken statues and"+
	" shattered religious symbols litter the ground.",
	"ceiling" : "The religious symbols that used to hang from the ceiling"+
	" have all fallen and shattered. At least this part of the temple appears"+
	" fairly sturdy, the roof keeps out most of the rain.",
	({"wall","walls"}) : "A few religious symbols are still desperately"+
	" clinging to the walls.",
	({"statues","broken statues"}) : "Statues that used to sit on the shelves"+
	" around the walls now lay broken on the floor.",
	({"symbols","religious symbols"}) : "A few religious symbols cling to the"+
	" walls, but most have fallen to the floor and shattered. Not even the"+
	" gods protected this place.",
	]));
	set_exits(([
	"west" : ROOMS+"ruins5",
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
