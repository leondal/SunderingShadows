//Octothorpe (4/23/13)
//Attaya Jungle Path 52
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun51",
     "east":JGL"jun53",
   ]));	 
}
