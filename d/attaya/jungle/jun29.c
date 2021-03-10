//Octothorpe (3/26/10)
//Attaya Jungle Path 29
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun28",
     "north":JGL"jun30",
   ]));	 
}