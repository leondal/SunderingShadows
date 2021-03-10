//Octothorpe (3/26/10)
//Attaya Jungle Path 10
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun11",
     "east":JGL"jun9",
   ]));	 
}