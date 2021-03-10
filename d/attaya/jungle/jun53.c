//Octothorpe (4/23/13)
//Attaya Jungle Path 53
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun47",
     "west":JGL"jun52",
     "east":JGL"jun54",
   ]));	 
}