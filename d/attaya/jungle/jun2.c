//Octothorpe (3/22/10)
//Attaya Jungle Path 2
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "southwest":JGL"jun1",
     "east":JGL"jun3",
     "south":JGL"jun36"
   ]));	 
}