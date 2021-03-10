//Octothorpe (4/22/13)
//Attaya Jungle Path 44
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun50",
     "south":JGL"jun41",
     "east":JGL"jun45",
   ]));	 
}