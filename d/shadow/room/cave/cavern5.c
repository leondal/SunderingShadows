/******NOTE - Down after goblin caverns (northwestern route) ******/
//cavern5.c
#include "../cave.h"
#include "ddcaves.h"

inherit CROOM;

int searched;
void pick_critters();

void create(){
    pick_critters();
    ::create();
    set_repop(75);
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
      "scraps and broken bits of weaponry and armor littering the floor.  A steady dripping "+
      "of water falls from the ledge, forming a tiny pool.  The walls here are cracked and "+
      "seem to open into small recesses in various places."+
      "\n"
   );
    set_exits(([
	"up" : CAVEDIR+"cave49"
    ]));
    set_items(([
      (({"cave","cavern","room"})) : "The cool, damp air inside the cavern makes it "+
         "seem even larger somehow.  The rock walls seem naturally carved, as they are "+
         "very rough and jagged.  Faint waterlines can be seen in various places along the "+
         "walls, suggesting the source of the cavern as an underground river.  The walls here "+
         "are not smooth like the rest of the caverns.  They are cracked and open, leaving small "+
         "recesses.",
      (({"recess","recesses"})) : "One small hole in particular catches your eye.  It is in the eastern "+
         "wall and looks like it might be hiding something.",
      (({"items","junk","weapons","weaponry","armor","scraps","bits"})) : "Scattered all along "+
         "the dirty floor of this cavern are broken pieces of weaponry and armor mixed with "+
         "disgusting scraps of food.  The food is rancid, long past the point it could be "+
         "eaten, and the broken sword blades and axe heads suggest that the occupants of this "+
         "cave are anything but kind.",
      "encampment" : "Judging from the size and condition of the broken things lying around the "+
         "floor, combined with the stench of the cavern, this seems to be an arming place for "+
         "goblins.",
      (({"water","dripping","pool"})) : "A light, steady dripping of water from the ledge above forms "+
         "the smallest of pools in a recess in the floor.  What must have once been quite a river has "+
         "now been dried to this slow trickle here.  Looking closer, it seems the dark water might be "+
         "hiding something.",
      "ledge" : "A narrow, jutting ledge partially blocks the view to the tunnels above.  The "+
         "edge of the outcropping seems jagged and rough."
    ]));
    set_smell("default","There is a strong rotting smell about the place.");
    set_listen("default","The sound of dripping water fills your ears."); 
    set_search("default","You find a small recess in the eastern wall.");
    set_search("recess", (: "search_hole" :) );
    set_search("hole", (: "search_hole" :) );
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"goblin",MONDIR+"goblincaptain"}),70,15);
}
*/
void search_hole(string str) {
   if(present("cave kobold")) {
      write("The kobold seems to be in the way of your searching!");
      return;
   }
   if(searched) {
     write("You find nothing but pebbles and dust in the hole.");
     return;
   }
   switch(random(3)) {
      case 0: new(DDOBJ"electrumring")->move(TO);  break;
      case 1: new(DDOBJ"leatherring")->move(TO);  break;
      case 2: new(DDOBJ"lightningring")->move(TO);  break;
   }
   write("%^BOLD%^You find something that someone must have packed away.\n");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" finds something in a hole in the wall.", TP);
   searched = 1;
   return;
} 

void reset() {
   int active;
   active = has_mobs();
   if(!active){
     if(mons)  mons = ([]);
     pick_critters();
   }
	::reset();
	if(!random(3)) searched = 0;
}

void pick_critters(){
     switch(random(15)){
        case 0..2:  break;
        case 3:  set_monsters( ({MONDIR+"koboldchild"}),({1}));
                 break;
        case 4:  set_monsters( ({MONDIR+"kobold"}),({1}));
                 break;
        case 5:  set_monsters( ({MONDIR+"koboldcaptain"}),({1}));
                 break;
        case 6:  set_monsters( ({MONDIR+"koboldmage"}),({1}));
                 break;
        case 7:  set_monsters( ({MONDIR+"koboldthief"}),({1}));
                 break;
        case 8:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"kobold"}),({1,random(1)+1}));
                 break;
        case 9:  set_monsters( ({MONDIR+"koboldcaptain",MONDIR+"koboldthief"}),({1,1}));
                 break;
        case 10:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"koboldthief"}),({1,random(2)+1}));
                 break;
        case 11:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"koboldthief",MONDIR+"koboldmage"}),({1,1,1}));
                 break;
        case 12:  set_monsters( ({MONDIR+"koboldcaptain",MONDIR+"kobold"}),({1,random(3)+2}));
                 break;
        case 13:  set_monsters( ({MONDIR+"koboldchild"}),({random(3)+2}));
                 break;
        case 14:  set_monsters( ({MONDIR+"koboldmage",MONDIR+"koboldthief"}),({random(2),random(3)}));
                 break;
      }
}