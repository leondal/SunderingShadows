//Octothorpe (4/21/13)
//Attaya Jungle Path 41
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun44",
     "east":JGL"jun42",
   ]));	 
}