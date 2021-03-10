#include <std.h>
#include "../dragon.h";

inherit BPRISON;

int opened;
int mob;

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
      "south" : TOWER+"prison04",
      "stairs" : TOWER+"prison08"
   ]) );
   opened = 0;
   mob = 1;
}

void init() {
   ::init();
   add_action("move_containers","move");
   add_action("squeeze_through","squeeze");
}

int squeeze_through(string str) {
object ob;
   if(!str) {
      write("What do want to squeeze through?");
      return 1;
   }
      if(str == "opening") {
      write("Do you want to squeeze %^BOLD%^through%^RESET%^ something?");
      return 1;
   }
      if(str == "through") {
      write("Squeeze through what?");
      return 1;
   }
   if(!opened) {
      write("You bump into the containers.");
      return 1;
   }
   if(str == "through opening") {
      if(mob) {
         write("%^BOLD%^%^BLUE%^When trying to pass through the opening, you disturb a coffin and a skeleton comes out!");
         tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" trys to pass through the opening and disturbs a coffin, setting a skeleton free!",TP);
         ob = new(MON+"g_undead")->move(TO);
         mob = 0;
         return 1;
      }
   write("You move through the opening into the empty cell.");
   tell_room(TO,""+TPQCN+" moves through the opening into the empty cell.",TP);
   TP->move_player(TOWER+"prison14");
   return 1;
   }
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
      tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" moves some containers out of the way and exposes an empty cell. Maybe you can squeeze through the opening?",TP);
      tell_object(TP,"%^BOLD%^%^BLACK%^You move some containers out of the way and expose an empty cell. The %^YELLOW%^opening%^BOLD%^%^BLACK%^ looks big enough to %^YELLOW%^squeeze through%^BLACK%^.");
      opened = 1;
      return 1;
   }
}