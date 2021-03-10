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
	set_short("A dirt path");
	set_long(
	"You are travelling on a small dirt path that runs east and west. On"+
	" either side of the road are trees that have been scorched. Most remain"+
	" standing, but charred black. The trees give you a creepy feeling,"+
	" they have an almost sinister feel to them. To the west the path"+
	" continues to the graveyard.",
	);
	set_smell("default","The scent of burnt trees chokes the air.");
	set_listen("default","The trees are silent.");
	set_items(([
	({"path","dirt path"}) : "%^ORANGE%^A small dirt path runs through the"+
	" trees here, linking the graveyard to the rest of the ruins.",
	({"trees","scorched trees","burnt trees"}) : "%^BOLD%^%^BLACK%^The trees"+
	" that line either side of the road have been charred black. They might"+
	" once have been vibrant and lovely, but are now just blackened husks."+
	" They have a rather sinister feeling about them.",
	"graveyard" : "You can see the entrance of the graveyard to the west.",
	]));
	set_exits(([
	"west" : ROOMS+"ruins12",
	"east" : ROOMS+"ruins9",
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
