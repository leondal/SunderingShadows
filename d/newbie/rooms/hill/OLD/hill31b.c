//hill31b.c - hobgoblin lair

#include "../../newbie.h"

inherit VAULT;
int items;

void create(){
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);   
   set_short("%^BOLD%^%^BLACK%^Hobgoblin Lair%^RESET%^");
   set_long(
@STYX
You've definitely found your way somewhere you aren't going to be welcome.  This is a very large cave dug into the hillside, perhaps the opening of an old mine that was begun but then abandoned by the original creators.  Now it's obviously home to crude humanoids, no doubt the hobgoblins you've had to fight to get in and be able to poke around.  Piles of skins and scraps of armor and who knows what else lie scattered around.
STYX
   );
   set_smell("default","The room smells like damp earth and musty leather.");
   set_listen("default","The earthen walls absorb much of the noise you're making.");
   set_items( ([ "walls": "The walls and ceiling are mostly dirt shored up with crude wooden beams here and there.", 
	({"piles", "scraps", "skins"}):"%^BOLD%^%^RED%^The skins and piles of whatever the hobgoblins have stolen or taken from their victims smell musty and lie in various piles around the room.%^RESET%^",
	]) );
   set_exits(([
       "gate":HILL"hill31a",
   ]));
   set_door("gate","/d/newbie/rooms/hill/hill31a","gate",0);
   set_door_description("gate", "This is a crude gate made from tree limbs lashed together with leather straps.");
   set_string("gate","open","The gate groans loudly as it swings open.");
   set_search("piles", (: TO, "search_stuff" :) );
   set_search("skins", (: TO, "search_stuff" :) );
   set_search("scraps", (: TO, "search_stuff" :) );
}

void init() {
        ::init();
}

void reset() {
	::reset();
	if(!items) items=1;
	if( (random(5) < 3) && (!present("hobmonster")) ) {	
	    switch(random(4)) {
    		case 0: 
   		    	new(HILL"mon/hobgobf")->move(TO);
   		    	new(HILL"mon/hobgob")->move(TO);
			new(HILL"mon/hobgobf2")->move(TO);
    		   	new(HILL"mon/hobgobfe")->move(TO);
  		    	break;
   		case 1:
    		   	new(HILL"mon/hobgobfe")->move(TO);
    			new(HILL"mon/hobgobf")->move(TO);
    			new(HILL"mon/hobgobf2")->move(TO);
			break;
    		case 2:	
    			new(HILL"mon/hobgob")->move(TO);
			new(HILL"mon/hobgob")->move(TO);
    		   	new(HILL"mon/hobgobf2")->move(TO);
			new(HILL"mon/hobgobfe")->move(TO);
    		   	new(HILL"mon/hobgobfe")->move(TO);
			break;
		case 3:
    			new(HILL"mon/hobgob")->move(TO);
    			new(HILL"mon/hobgobf")->move(TO);
			new(HILL"mon/hobgobfe")->move(TO);
    		   	new(HILL"mon/hobgobf2")->move(TO);
			new(HILL"mon/hobgobfe")->move(TO);
			break;			
	    }
	}
}

void search_stuff(string str) {
  object ob;
  if(present("hobmonster")) {
     write("The hobgoblins are in your way.");
     return;
  }   
  if(!items) {
     write("It looks like someone has looted anything worthwhile recently.");
     return;
  }
  switch(random(20)) {
        case 0..1:
	  "/d/common/daemon/randstuff_d"->find_stuff(TO, "component");
// yes, I meant to leave the break out here *Styx*
        case 2:
	  ob = new("/d/magic/safe_scroll");
	  ob->set_spell(3);
	  ob->move(TO);
	  tell_room(TO, "%^BOLD%^It looks as though a magely type has been one of their victims...");
	  break;
        case 3:
	  "/d/common/daemon/randstuff_d"->find_stuff(TO, "kit");
	  write("%^BOLD%^You find a kit of potions in the mess.\n");
	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a kit of potions in the mess.\n", TP);
	  break;
        case 4:
	  ob = new("/std/obj/coins");
	  ob->set_money("silver", random(250)+10);
	  ob->set_money("copper", random(200)+50);
	  ob->move(TO);
	  write("%^BOLD%^You find several coins in your digging but maybe your companions haven't noticed yet.\n");
	  break;
	case 5:
	  new(MISC"gem")->move(TO);
	  write("%^BOLD%^You find a nice gem hidden under one of the piles!");
	  break;
	case 6:
      	  write("%^BOLD%^You've found a crumpled and blood-stained piece of paper.\n");
      	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a crumpled, blood-stained piece of paper.\n", TP);
      	  ob = new("/d/newbie/rooms/forest/stuff/journal");
	  ob->move(TO);
       	  break;
        case 7:
	  "/d/common/daemon/randstuff_d"->find_stuff(TO, "stuff");
	  tell_room(TO, "%^BOLD%^It seems the searching wasn't entirely in vain.");
	  break;
	case 8:
	  write("%^BOLD%^You find a scroll that they apparently had little interest in.\n");
	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a scroll in one of the piles.\n", TP);
  	  ob = new("/d/magic/scroll");
          ob->set_spell(2);
          ob->move(TO);
	  break;
	case 9:
  	  ob = new("/d/magic/safe_scroll");
          ob->set_spell(3);
          ob->move(TO);
	  write("%^BOLD%^You find a scroll that they apparently had little interest in.\n");
	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a scroll in one of the piles.\n", TP);
	  break;
        default: 
	  write("There doesn't seem to be anything worthwhile there at the moment.");
	  tell_room(TO, TPQCN+" doesn't seem to find anything worthwhile.", TP);
    }
    items = 0;
} 
