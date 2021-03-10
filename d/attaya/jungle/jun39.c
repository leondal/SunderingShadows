//Octothorpe (4/21/13)
//Attaya Jungle Path 39
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun38",
     "east":JGL"jun36",
   ]));	 
}