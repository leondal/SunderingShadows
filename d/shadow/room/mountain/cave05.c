//cave05.c
#include <std.h>
#include "echoes.h"
#define RANDSTUFF "/d/common/daemon/randstuff_d"

inherit ECHOES;
int searched;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic workmanship suggest "+
      "that the dwarves who make their home here have expanded and improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings %^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along the walls between the arches, "+
      "creating a sense of being in the open air despite the drab walls of the tunnels.  It seems "+
      "to be getting darker here, and the walls close in slightly, forming more of a cave here "+
      "at the end of the tunnel.  Several scraps of bones litter the floor here."+
      "\n"
    );

      add_item("bones","A pile of bones rests in the corner, all of them gnawed.  You think "+
        "you catch a glimpse of something else underneath.");
 
    set_exits(([
        "south" : ROOMS"cave04"
   	]));
   set_search("default","The large pile of bones in the corner gets your attention.");
   set_search("pile", (: TO, "search_pile" :) );
   set_search("bones", (: TO, "search_pile" :) );
}

void reset() {
  ::reset();
  if(!random(3)) searched = 0;
  if(!present("troll")) {
    new("/d/deku/monster/troll")->move(TO);
    new("/d/deku/monster/troll")->move(TO);
  }
}

void search_pile(string str) {
   if(present("troll")) {
     write("The trolls aren't about to let you do that.");
     return;
   }
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(!random(3)) {
      write("It looks like they are mostly humanoid remains with nothing of value.");
      tell_room(ETP,""+TPQCN+" searches the bones and looks disappointed.", TP);
      searched = 1;
      return;
   }
   RANDSTUFF->find_stuff(TO,"random");
   write("%^BOLD%^You find something the trolls must have tossed aside "
       "with the bones.\n");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" finds something in the pile of bones.", TP);
   searched = 1;
   return;
} 
