#include "../dragon.h";

inherit BPRISON;

int opened;

void create () {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This is the main hall of the prison. Above your"+
      " head are the cells that the prisoners were kept with this prison"+
      " was active. The long dark hall runs north to south with stairs"+
      " leading up to the cells. The stone floor here is smooth, but damp"+
      " just like the rest of the old structure. Along the hall you see"+
      " various containers lining the walls, blocking your view of the lower"+
      " cells. Unlike all the containers found in the bottom cellar, these look"+
      " new and recently placed."
   );
   set_items( ([
      "floor" : "The floor is damp and bare.",
      "containers" : "There are crates, coffins, and barrels. Moving them might allow you a better look into the lower cells.",
      "coffins" : "There are various types of coffins lined up against the edges of the hallway.",
      "crates" : "There are several large crates lined up against the edges of the hallway.",
      "barrels" : "There are barrels lined up against the edges of the hallway with the crates and coffins.",
      "cells" : "There cells above you on the next level up.",
   ]) );
   set_exits( ([
      "north" : TOWER+"prison05",
      "south" : TOWER+"prison03",
      "stairs" : TOWER+"prison07"
   ]) );
   opened = 0;
}

void init() {
   ::init();
   add_action("move_containers","move");
}

int move_containers(string str) {
   if(!str) {
      write("What do you want to move?");
      return 1;
   }
   if(opened) {
      write("The containers have already been moved.");
      return 1;
   }
   if((str == "containers") || (str == "coffins") || (str == "barrels") || (str == "crates")) {
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" moves some containers out of the way and exposes a cell filled with dead bodies!",TP);
      tell_object(TP,"%^BOLD%^%^RED%^You move some containers out of the way and expose a cell full of dead bodies!");
      opened = 1;
      return 1;
   }
}
