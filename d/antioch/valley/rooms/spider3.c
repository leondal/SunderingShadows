#include <std.h>
#include "../valley.h"
inherit ROOM;

int found = 0;

void create()
{
	::create();
   set_terrain(HUT);
   set_travel(FOOT_PATH);
	set_property("indoors",3);
	set_property("light",3);
	set_short("%^BOLD%^%^WHITE%^Spider's Nest");
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
	" Some skulls litter the ground from past meals."+
	" A few large egg sacks have been carefully fastened"+
	" to the trunks of a tree, out of the way of the"+
	" thrashing animals."
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
   "egg sacks" : "Some very large egg sacks have been"+
	" secured to the tree trunks. You can't imagine"+
	" they've been left unguarded."
	]) );
	set_search("egg sacks",(:TO,"search_eggs":));
	set_exits( ([
	"southwest" : ROOMS+"spider2",
	"northwest" : ROOMS+"spider4"
	]) );
}

int search_eggs()
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(found) {
		write("As you begin to search through, you"+
		" realize that there are nothing but empty sacks"+
		" here and all the eggs have been moved someplace"+
		" else.");
		return 1;
	}
	if(present("spider")) {
		write("The spiders will not let you touch their precious"+
		" egg sacks!");
		return 0;
	}
	else {
		write("%^RED%^As you move towards the eggs"+
		" you hear a clicking noise from up above.");
		write("\n");
		write("\n");
		write("%^RED%^Several large, very angry spiders"+
		" descend through the web work to defend their"+
		" eggs!");
		say("%^RED%^As "+TP->query_cap_name()+" moves"+
		" towards the eggs a clicking noise begins from"+
		" above.");
		say("\n");
		say("\n");
		say("%^RED%^Several large, very angry spiders"+
		" descend through the web work to defend their"+
		" eggs!");
		switch(random(4)) {
			case 0:
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				break;
			case 1:
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				break;
			case 2:
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				break;
			case 3:
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				new(MONS+"spider")->move(this_object());
				break;
		}
		found = 1;
		add_item(
		"egg sacks","It looks like there were once egg sacks attached"+
		" to the tree, but someone's removed them.");
		new(OBJ+"spider_eggs.c")->move(TP);
		return 1;
	}
}

void reset()
{
	::reset();
	if(found) {
		found = 0;
		return 1;
	}
	if(!present("spider")) {
		switch(random(3)) {
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
		}
	}
}
