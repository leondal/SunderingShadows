//Octothorpe (4/22/13)
//Attaya Jungle Path 46
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun43",
     "west":JGL"jun45",
     "east":JGL"jun47",
   ]));	 
}