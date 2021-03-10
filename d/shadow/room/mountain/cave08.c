//cave08.c
#include <std.h>
#include "echoes.h"
#define RANDSTUFF "/d/common/daemon/randstuff_d"

inherit ECHOES;
int searched;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic workmanship suggest "+
      "that the dwarves who make their home here have expanded and improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings %^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along the walls between the arches, "+
      "creating a sense of being in the open air despite the drab walls of the tunnels.  The "+
      "tunnel dead ends here, and it seems to have been forgotten by the dwarves, or at least "+
      "rarely visited.  Rubble has been allowed to pile up in the northwestern corner, and "+
      "dark spots on the walls suggest it has not been maintained." +
      "\n"
    );
    add_item("rubble","A pile of broken rocks mixed with fouler things stands in the "+
      "northwestern corner.  It looks as though it might be hiding something.");
    set_exits(([
        "south" : ROOMS"cave07"
   	]));
   set_smell("default","The air is especially stale here.");
   set_search("default","The pile of rubble in the corner gets your attention.");
   set_search("pile", (: TO, "search_pile" :) );
   set_search("rubble", (: TO, "search_pile" :) );
}

void reset() {
  object liz;
  ::reset();
  if(random(2)) {
    searched = 0;
    if(!present("lizard", TO)) {
      new(MOBS"lizard")->move(TO);
      new(MOBS"lizard")->move(TO);
    }
  }
}

void search_pile(string str) {
   if(present("lizard")) {
     write("A lizard is crawling around it and is in the way!");
     return;
   }
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(!random(3)) {
      write("All you find this time are more rocks and a few decaying bones.");
      tell_room(ETP,""+TPQCN+" searches the rubble and looks disappointed.", TP);
      searched = 1;
      return;
   }
   RANDSTUFF->find_stuff(TO,"random");
   write("%^BOLD%^%^BLUE%^You find stuff someone probably hid here.\n");
   tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" finds something in the rubble.", TP);
   searched = 1;
   return;
} 
