/******NOTE - after hobgoblin caves - southwestern passage******/
//cavern6.c
#include <std.h>
#include "../cave.h"

inherit ROOM;

int ring,medallion,wand;

void check_complete();

void create(){
    ::create();
    set_property("light",1);
    set_indoors(1);
    set_property("no sticks", 1);
    set_terrain(NAT_CAVE);
    set_travel(RUBBLE);
    set_name("Dragon's Den Caverns");
    set_short("Dragon's Den Caverns");
    set_long(
      "%^BOLD%^You are in the Dragon's Den Caverns.%^RESET%^\n"+
      "The damp air inside this cavern makes it feel quite cool and clammy.  Descending "+
      "from above, the cave widens to form this recessed cavern below the main tunnels.  "+
      "Though the cavern is mostly empty, several items strewn around the room suggest "+
      "that it is not entirely deserted.  It seems to be an encampment of some sort, with "+
      "scraps and broken bits of weaponry and armor littering the floor.  A larger pile "+
      "of debris seems to be near the northern part of the cave, underneath the overhanging "+
      "ledge.  A steady dripping of water falls from the ledge, forming a tiny pool."+
      "\n"
    );
    set_exits(([
	"up" : CAVEDIR+"cave59",
    ]));
    set_items(([
      (({"cave","cavern","room"})) : "The cool, damp air inside the cavern makes it "+
         "seem even larger somehow.  The rock walls seem naturally carved, as they are "+
         "very rough and jagged.  Faint waterlines can be seen in various places along the "+
         "walls, suggesting the source of the cavern as an underground river.",
      (({"items","junk","weapons","weaponry","armor","scraps","bits"})) : "Scattered all along "+
         "the dirty floor of this cavern are broken pieces of weaponry and armor mixed with "+
         "disgusting scraps of food.  The food is rancid, long past the point it could be "+
         "eaten, and the broken sword blades and axe heads suggest that the occupants of this "+
         "cave are anything but kind.",
      "encampment" : "Judging from the size and condition of the broken things lying around the "+
         "floor, combined with the stench of the cavern, this seems to be an arming place for "+
         "hobgoblins.",
      (({"pile","debris"})) : "Near the northern edge of the cavern, a pile of debris has been heaped "+
         "higher than the others.",
      (({"water","dripping","pool"})) : "A light, steady dripping of water from the ledge above forms "+
         "the smallest of pools in a recess in the floor.  What must have once been quite a river has "+
         "now been dried to this slow trickle here.",
      "ledge" : "A narrow, jutting ledge partially blocks the view to the tunnels above.  The "+
         "edge of the outcropping seems jagged and rough."
    ]));
    set_smell("default","There is a strong rotting smell about the place.");
    set_listen("default","The sound of dripping water fills your ears."); 
    set_search("default","The pile of debris in the northern extremity of the cave catches your interest.");
    set_search("pile", (: "search_pile" :) );
    set_search("debris", (: "search_pile" :) );
}

void init(){
    ::init();
//	do_random_encounters(({MONDIR+"hobgoblin",MONDIR+"hobgoblincaptain"}),80,15);
	add_action("place_it","place");
    	ring = 0;
    	wand = 0;
    	medallion = 0;
}
void reset(){
    ::reset();
}

void search_pile(string str) {
	object obj;
/*
   if(present("hobgoblin")) {
      write("The menacing hobgoblin will not let you search the pile!");
      return;
   }
This is not needed any more.  There aren't even any hobgoblins
here now :P Circe 11/21/04
*/
        if(present("statue",TO)){
            write("You have found a small statue.");
            return 1;
        }
	obj = new("/d/shadow/obj/misc/cave_statue");
	obj->move(TO);
	tell_room(ETP,TPQCN+" finds something.",TP);
	write("You have found a small statue.");
} 

int place_it(string str){
  string what,where,action;
  object obj;
    if(!(present("statue",TO))) return 0;
    if(!str) return notify_fail("Place what where?\n");
    if(sscanf(str,"%s %s %s",what,action,where) != 3)
      return notify_fail("Place what where?\n");
    if((int)TP->query_alignment() == 1 || (int)TP->query_alignment() == 2 || (int)TP->query_alignment() == 3) {
	if(what == "ring"){
	    if(ring) return notify_fail("The ring is already there!\n");
	    if(where != "finger") return notify_fail("'Place ring on finger' is the proper syntax!\n");
	    if(action != "on") return notify_fail("'Place ring on finger' is the proper syntax!\n"); 
	    if(!(obj = present("electrum cave ring",TP))) return notify_fail("You don't have the right ring!\n");
	    write("You place the ring on the statue's finger.");
	    tell_room(ETP,TPQCN+" puts something on the statue's finger.",TP);
	    obj->remove();
	    ring = 1;	
	    check_complete();
	    return 1;
	} 
	else if(what == "wand"){
	    if(wand) return notify_fail("The wand is already there!\n");
	    if(where != "hand") return notify_fail("'Place wand in hand' is the proper syntax!\n");
	    if(action != "in") return notify_fail("'Place wand in hand' is the proper syntax!\n"); 
	    if(!(obj = present("platinum cave wand",TP))) return notify_fail("You don't have the right wand!\n");
	    write("You place the wand in the statue's hand.");
	    tell_room(ETP,TPQCN+" puts something in the statue's hand.",TP);
	    obj->remove();
	    wand = 1;	
	    check_complete();
	    return 1;
	} 
	else if(what == "medallion"){
	    if(medallion) return notify_fail("The medallion is already there!\n");
	    if(where != "neck") return notify_fail("'Place medallion around neck' is the proper syntax!\n");
	    if(action != "around") return notify_fail("'Place medallion around neck' is the proper syntax!\n");
	    if(!(obj = present("glass cave medallion",TP))) return notify_fail("You don't have the right medallion!\n");
	    write("You place the medallion around the statue's neck.");
	    tell_room(ETP,TPQCN+" puts something around the statue's neck.",TP);
	    obj->remove();
	    medallion = 1;	
	    check_complete();
	    return 1;
	} 
	else return 0;
    }
    else if((int)TP->query_alignment() == 4 || (int)TP->query_alignment() == 5 || (int)TP->query_alignment() == 6) {
	if(what == "ring"){
	    if(ring) return notify_fail("The ring is already there!\n");
	    if(where != "finger") return notify_fail("'Place ring on finger' is the proper syntax!\n");
	    if(action != "on") return notify_fail("'Place ring on finger' is the proper syntax!\n"); 
	    if(!(obj = present("leather cave ring",TP))) return notify_fail("You don't have the right ring!\n");
	    write("You place the ring on the statue's finger.");
	    tell_room(ETP,TPQCN+" puts something on the statue's finger.",TP);
	    obj->remove();
	    ring = 1;	
	    check_complete();
	    return 1;
	} 
	else if(what == "wand"){
	    if(wand) return notify_fail("The wand is already there!\n");
	    if(where != "hand") return notify_fail("'Place wand in hand' is the proper syntax!\n");
	    if(action != "in") return notify_fail("'Place wand in hand' is the proper syntax!\n"); 
	    if(!(obj = present("granite cave wand",TP))) return notify_fail("You don't have the right wand!\n");
	    write("You place the wand in the statue's hand.");
	    tell_room(ETP,TPQCN+" puts something in the statue's hand.",TP);
	    obj->remove();
	    wand = 1;	
	    check_complete();
	    return 1;
	} 
	else if(what == "medallion"){
	    if(medallion) return notify_fail("The medallion is already there!\n");
	    if(where != "neck") return notify_fail("'Place medallion around neck' is the proper syntax!\n");
	    if(action != "around") return notify_fail("'Place medallion around neck' is the proper syntax!\n");
	    if(!(obj = present("rose cave medallion",TP))) return notify_fail("You don't have the right medallion!\n");
	    write("You place the medallion around the statue's neck.");
	    tell_room(ETP,TPQCN+" puts something around the statue's neck.",TP);
	    obj->remove();
	    medallion = 1;	
	    check_complete();
	    return 1;
	} 
	else return 0;
    }
    else if((int)TP->query_alignment() == 7 || (int)TP->query_alignment() == 8 || (int)TP->query_alignment() == 9) {
	if(what == "ring"){
	    if(ring) return notify_fail("The ring is already there!\n");
	    if(where != "finger") return notify_fail("'Place ring on finger' is the proper syntax!\n");
	    if(action != "on") return notify_fail("'Place ring on finger' is the proper syntax!\n"); 
	    if(!(obj = present("lightning cave ring",TP))) return notify_fail("You don't have the right ring!\n");
	    write("You place the ring on the statue's finger.");
	    tell_room(ETP,TPQCN+" puts something on the statue's finger.",TP);
	    obj->remove();
	    ring = 1;	
	    check_complete();
	    return 1;
	} 
	else if(what == "wand"){
	    if(wand) return notify_fail("The wand is already there!\n");
	    if(where != "hand") return notify_fail("'Place wand in hand' is the proper syntax!\n");
	    if(action != "in") return notify_fail("'Place wand in hand' is the proper syntax!\n"); 
	    if(!(obj = present("storm cave wand",TP))) return notify_fail("You don't have the right wand!\n");
	    write("You place the wand in the statue's hand.");
	    tell_room(ETP,TPQCN+" puts something in the statue's hand.",TP);
	    obj->remove();
	    wand = 1;	
	    check_complete();
	    return 1;
	} 
	else if(what == "medallion"){
	    if(medallion) return notify_fail("The medallion is already there!\n");
	    if(where != "neck") return notify_fail("'Place medallion around neck' is the proper syntax!\n");
	    if(action != "around") return notify_fail("'Place medallion around neck' is the proper syntax!\n");
	    if(!(obj = present("lava cave medallion",TP))) return notify_fail("You don't have the right medallion!\n");
	    write("You place the medallion around the statue's neck.");
	    tell_room(ETP,TPQCN+" puts something around the statue's neck.",TP);
	    obj->remove();
	    medallion = 1;	
	    check_complete();
	    return 1;
	} 
	else return 0;
    }
    else return 0;
}
void check_complete(){

	if((ring) && (wand) && (medallion)){
		tell_room(ETP,"The statue starts glowing, then suddenly dissapears.");
		present("statue",TO)->remove();
		tell_room(ETP,TPQCN+" starts glowing, then suddenly dissapears.",TP);
		TP->move(CAVEDIR+"cave_quest_room");
		write("You find yourself in another cavern!");
            TP->force_me("look");
	}
}
