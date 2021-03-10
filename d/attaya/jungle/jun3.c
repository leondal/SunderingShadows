//Octothorpe (3/22/10)
//Attaya Jungle Path 3
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun37",
     "west":JGL"jun2",
     "east":JGL"jun4"
   ]));	 
}