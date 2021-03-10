#include <std.h>
#include "../valley.h"
inherit ROOM;

int found = 0;

void create()
{
	::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
	set_property("outdoors",2);
	set_property("light",2);
	set_short("Ogre Camp");
	set_long(
	"You've stumbled upon a camp of ogres!"+
	" A kettle with some sort of rotting meat is"+
	" hanging over a burning fire. Huge trees have"+
	" been cut into logs and placed around the fire as"+
	" chairs. There are several bones of different"+
	" animals littered around the edges of the camp."
	);
	set_smell("default",
	"You smell the stench of rotting meat."
	);
	set_listen("default",
	"The fire hisses and pops."
	);
	set_items( ([
	"kettle" : "It is a large black pot that has some"+
	" sort of stew boiling in it.",
	"stew" : "The stew is a reddish color with large"+
	" chunks of meat in it that looks disgusting.",
	"fire" : "The fire is burning low having almost"+
	" run out of wood.",
	"logs" : "These logs have sunk into the ground as"+
	" though many large creatures have been sitting on"+
	" it.",
	"bones" : "Various bones are scattered about the"+
	" camp, most of them partially crushed but some"+
	" have a bit of flesh still clinging to them."
	]) );
	set_search("kettle",(:TO,"find_food":));
	found = 0;
	set_exits( ([
	"south" : ROOMS+"dt31"
	]) );
}

int find_food()
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if((string)TP->query_race() != "ogre") {
		write("You find nothing you'd want to eat.");
		return 1;
	}
	if(found) {
		write("You search but all the food is gone.");
		return 1;
	}
	else {
		write("You find some meat.");
		new(OBJ+"meat")->move(this_object());
		found = 1;
		return 1;
	}
}

void reset()
{
	::reset();
	if(!present("ogre")) {
		switch(random(5)) {
		case 0:
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			break;
		case 1:
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			break;
		case 2:
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			break;
		case 3:
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			break;
		case 4:
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			new(MONS+"ogre.c")->move(this_object());
			break;
		}
	}
}
