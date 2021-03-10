//Octothorpe (3/26/10)
//Attaya Jungle Path 14
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun13",
     "north":JGL"jun15",
   ]));	 
}