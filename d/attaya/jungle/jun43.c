//Octothorpe (4/21/13)
//Attaya Jungle Path 43
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_property("wild magic",15);
   /*Yes, the exit rooms are intentionally illogical. Thundercracker originally had 
   all four exits going to jun2. I thought I'd be more evil and have them be three 
   separate rooms in different parts of the area - Octothorpe*/
   set_exits(([
     "north":JGL"jun2",
     "west":JGL"jun42",
     "east":JGL"jun59",
     "south":JGL"jun20",
   ]));
   set_post_exit_functions(({"north","east","south"}),({"lost","lost","lost"}));
}

void lost(){
   if(!living(TP)) return;
   tell_object(TP,"%^BOLD%^You feel like you've gotten turned around "+
      "somehow in the jungle and are now lost.%^RESET%^");
   return;
}

void reset(){
   ::reset();
   if(!present("red skeleton")){
      new(MON+"red_skeleton")->move(TO);
	}
}