//Octothorpe (4/23/13)
//Attaya Jungle Path 55
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun9",
     "south":JGL"jun49",
     "west":JGL"jun54",
     "southwest":JGL"jun48",
   ]));	 
}