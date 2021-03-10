//Octothorpe (4/23/13)
//Attaya Jungle Path 58
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun18",
     "west":JGL"jun57",
     "east":JGL"jun59",
   ]));	 
}