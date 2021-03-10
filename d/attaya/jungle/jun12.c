//Octothorpe (3/26/10)
//Attaya Jungle Path 12
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun13",
     "north":JGL"jun56",
	 "east":JGL"jun11"
   ]));	 
}

void reset(){
   ::reset();
   if(!present("wanderer")){
      new(MON"roper")->move(TO);
   }
}
