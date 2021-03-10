//Octothorpe (4/23/13)
//Attaya Jungle Path 56
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun12",
     "east":JGL"jun57",
   ]));	 
}