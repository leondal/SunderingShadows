//forest72c.c - A small cave

#include <std.h>
#include "../../newbie.h"
#include "forest.h"

inherit ROOM;

int items;

void create(){
items = 1;
   ::create();
   set_property("light",1);
   set_property("no teleport",1);
   set_property("indoors", 1);
//   set_property("no sticks",1);
   set_short("%^BOLD%^%^BLACK%^A small dark cave%^RESET%^");
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
   set_long(
@STYX
%^BOLD%^%^BLACK%^You've stepped inside the entrance to what appears to be a small cave.  The walls are fairly dry and the dirt under your feet is much smoother and packed than you might expect.  The ceiling is barely six foot above the floor.  The room is only about five feet across and slightly oblong being deepest opposite the opening you came through.  There is a pile of debris against the far wall that appears at a glance to consist mostly of sticks and leaves.
STYX
   );
   set_smell("default","There is a faint acidic smell.");
   set_listen("default","A rustling sound seems to be coming from the debris.");
   set_items( ([ 
   	({"pile","debris","leaves"}):"As you look closer, some of the leaves in the pile appear to be moving.",
	({"dirt", "floor"}):"The dirt floor appears to have been packed and smoothed out from wear.",
	"walls":"The walls are dirt with roots and rocks jutting out much like the sides of the ravine.",
	]) );
   set_search("pile", (: TO, "search_pile" :) );
   set_search("leaves", (: TO, "search_pile" :) );
   set_search("debris", (: TO, "search_pile" :) );
   set_exits( ([
      	"out":FOREST"forest72b",
       ]) );
}

void search_pile() { 
	if(items > 0) {
		if(random(4) == 0) {
       	write("An extremely large centipede must have died here some time ago.  You find a sturdy-looking and very sharp pincer among the other debris.\n");
       	say(TPQCN+" searches the debris and finds a sturdy-looking and very sharp pincer among the other debris.\n");
       	new(STUFF"centdagger")->move(TO);
   		items = 0;
		}
   	write("%^ORANGE%^Giant centipedes swarm out from under the debris when you disturb it! \n\nThey swarm around your feet and begin crawling up your legs.");
	say("%^ORANGE%^Giant centipedes swarm out from under the debris when "+TPQCN+" disturbs it! \n\nThey swarm around your feet and begin crawling up your legs.");
	switch(random(3)) {
		case 0:
			new(MONST"centipede")->move(TO);
		case 1:
			new(MONST"centipede")->move(TO);
				if(random(2) == 0)
				new(MONST"centipede2")->move(TO);
		case 2:
			new(MONST"centipede")->move(TO);
			new(MONST"centipede")->move(TO);
	}
	items = 0;
	}
	
   else {
  		write("The debris is already somewhat scattered from a recent search.  A few small centipedes writhe away into fist-sized holes in the wall.");
		say(TPQCN+" searches the scattered stuff and looks disappointed as small centipedes writhe away.");
	}
}

void reset() {
	::reset();
	if(random(6) < 3)
	if (!items) items=1;
}
