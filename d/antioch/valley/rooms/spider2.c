#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
        ::create();
   set_terrain(HUT);
   set_travel(FOOT_PATH);
   set_property("indoors", 1);
        set_property("light",0);
        set_short("Spider's Nest");
        set_long(
        "The forest is especially dark here and the trees"+
        " themselves seem rather sinister. Webbing hangs"+
        " down from the trees in giant strands, lashing"+
        " several of them together and forming a circle"+
        " around them. Only a group of enormous spiders"+
        " could have strung so much silk. There are several"+
        " large bundles wrapped in webbing, some of them"+
        " still twitching. Whatever poor animals are trapped"+
        " in there are simply waiting for their death."+
        " Some skulls litter the ground from past meals. "+
        "A tunnel here, coated in tangled webs, leads underground."
   );
   set_smell("default",
        "The smell of decay permeates the area."
        );
   set_listen("default",
        "A faint clicking noise can be heard from above."
        );
        set_items( ([
        "web" : "It is a rather unusual web, most of it is"+
        " wrapped around a group of trees in a circle but"+
        " when you look closely you can see almost invisible"+
        " strands extend into the nearby trees creating a"+
        " large network of web that disappears into the"+
        " foliage.",
        "nest" : "This must be the nest of several"+
        " incredibly large spiders.",
        "silk" : "The silk that the web is made of is very"+
        " varied, some of it is as thick as rope, but other"+
        " strands are very fine. You wouldn't want to get"+
        " stuck to it.",
        "animals" : "Most of the animals are already dead,"+
        " but a few are still futilely struggling.",
        "skulls" : "Skulls of various dead animals are"+
        " scattered about the ground.",
        ]) );
        set_exits( ([
        "northeast" : ROOMS+"spider3",
        "northwest" : ROOMS+"spider1",
        "down" : "/d/underdark/upper/t5r2"
        ]) );
}

void reset()
{
	::reset();
	if(!present("spider")) {
		switch(random(5)) {
			case 0:
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				break;
			case 1:
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				break;
			case 2:
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				break;
			case 3:
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				break;
			case 4:
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				new(MONS+"spider")->move(TO);
				break;
		}
	}
}
