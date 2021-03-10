//Octothorpe (3/26/10)
//Attaya Jungle Path 31a
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun30",
     "north":JGL"jun32",
   ]));	 
}