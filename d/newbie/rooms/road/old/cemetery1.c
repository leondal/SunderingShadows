//cemetery1.c - inherited room for cemetery w/undead, rats, snakes, & bats

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

object ob;

void create(){
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_short("%^ORANGE%^Rundown cemetery%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_long( (: TO, "ldesc" :) );
   set ("night long", (: TO, "ndesc" :) );
   set_smell("default","You smell the damp soil where the graves have been disturbed.");
   set_listen("default","You hear groaning sounds around the trees you hope is just the wind.");
   set_items( ([ 
   	"trees":"The gnarled trees cast eerie shadows of their own.", 
    ({"headstones", "headstone"}):"The writing on most of the headstones is only partially legible.  In most cases the soft stone has been damaged or simply worn and crumbled away.", 
	"fence" : "%^ORANGE%^The fence looks much like a series of rusty polearms standing on end a foot or so apart with horizontal bars holding them together.%^RESET%^",
	]) );
   set_exits(([
      "north":ROAD"road40",
      "east":ROAD"cemetery2",
      "south":ROAD"cemetery4",
      "southeast":ROAD"cemetery5",
   ]));
}

string ldesc(string str) {
   return("You've entered an overgrown and rundown cemetery.  Crumbling "
     "headstones have been knocked over and a few of the graves look like "
     "they've been dug up or disturbed in some fashion.  Gnarled trees grow "
     "along the fence marking the edges of the graveyard.  The grass is thin "
     "and looks trampled over where it's managed to grow very tall.");
}

string ndesc(string str) {
   return("You've entered an overgrown and rundown cemetery.  Crumbling "
      "headstones have been knocked over and a few of the graves look like "
      "they've been dug up or disturbed in some fashion.  Gnarled trees grow "
      "along the fence marking the edge of the graveyard.  %^BOLD%^%^BLACK%^The "
      "shadows from the moonlight and lanterns dance eerily across the "
      "ground.%^RESET%^");
}

void reset() {
	::reset();
   if( !present("skeleton") && !present("bat") && (query_night() == 1) && (random(10) < 3) ) {
	    switch(random(13)) {
			case 0..2:       
				new(MON"skeleton")->move(TO);
				break;
			case 3..4:       
				new(MON"zombiem")->move(TO);
				break;
			case 5..6:       
				new(MON"rat")->move(TO);
				new(MON"zombie")->move(TO);
				break;
			case 7..8:
				new(MON"skeleton")->move(TO);
				new(MON"zombie")->move(TO);
				break;
			case 9:
				new(MON"rat")->move(TO);
				new(MON"bat")->move(TO);
				new(MON"zombiem")->move(TO);
				break;				
			case 10:
				new(MON"bat")->move(TO);
				new(MON"skeleton")->move(TO);
				break;	
			case 11:
				new(MON"zombie")->move(TO);
				break;	
			case 12:
				new(MON"skeleton")->move(TO);
				new(MON"bat")->move(TO);
				new(MON"bat")->move(TO);
				new(MON"zombie")->move(TO);
				break;
		}
	}
	if( !present("rat") && !present("bat") && (query_night() == 0) && (random(10) < 3) ) {
	    switch(random(11)) {
			case 0..3:       
				new("/d/newbie/mon/rat")->move(TO);
				break;
			case 4..5:       
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				break;
			case 6..7:       
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 8:
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 9:
				new("/d/newbie/mon/snake")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 10:
				new("/d/newbie/mon/snake")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				break;				
		}
	}
}
