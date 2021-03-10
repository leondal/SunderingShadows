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
	set_short("Entrance to a graveyard");
	set_long(
	"You are outside the entrance of Antioch's old graveyard. Wrought iron"+
	" gates lead into the graveyard itself, they have been rusted stuck in"+
	" the open position. There does not seem to be too much disturbance to"+
	" this part of the city, just residual signs of a battle. The dirt path"+
	" leads away to the east."
	);
	set_smell("default","The scent of burnt trees chokes the air.");
	set_listen("default","The trees are silent.");
	set_items(([
	({"gates","wrought iron gates","iron gates"}) : "The wrought iron gates"+
	" were once rather beautiful, with elaborate designs made from the metal."+
	" Now they have been stuck rusted open.",
	({"path","dirt path"}) : "%^ORANGE%^A small dirt path leads back to the"+
	" east.",
	]));
	set_exits(([
	"east" : ROOMS+"ruins11",
	"enter" : ROOMS+"graveyard",
	]));
}

void reset()
{
	::reset();
	if(!present("monster") && query_night() == 1) {
		switch(random(5)) {
			case 0:
				new(MONS+"crypt_thing")->move(TO);
				new(MONS+"crypt_thing")->move(TO);
				new(MONS+"zombie_lord")->move(TO);
				break;
			case 1:
				new(MONS+"spectre")->move(TO);
				new(MONS+"spectre")->move(TO);
				new(MONS+"spectre")->move(TO);
				break;
			case 2:
				new(MONS+"spectre")->move(TO);
				new(MONS+"spectre")->move(TO);
				new(MONS+"crypt_thing")->move(TO);
				break;
			case 3:
				new(MONS+"zombie_lord")->move(TO);
				new(MONS+"crypt_thing")->move(TO);
				new(MONS+"crypt_thing")->move(TO);
				new(MONS+"spectre")->move(TO);
				new(MONS+"spectre")->move(TO);
				break;
			case 4:
				new(MONS+"crypt_thing")->move(TO);
				new(MONS+"zombie_lord")->move(TO);
				new(MONS+"spectre")->move(TO);
				new(MONS+"spectre")->move(TO);
				break;
		}
	}
}
