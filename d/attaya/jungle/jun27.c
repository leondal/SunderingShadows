//Octothorpe (3/26/10)
//Attaya Jungle Path 27
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun26",
     "east":JGL"jun28",
   ]));	 
}