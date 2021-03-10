//Octothorpe (4/22/13)
//Attaya Jungle Path 45
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun44",
     "east":JGL"jun46",
   ]));	 
}