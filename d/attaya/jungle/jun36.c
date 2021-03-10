//Octothorpe (3/22/10)
//Attaya Jungle Path 36
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun35",
     "north":JGL"jun2",
     "west":JGL"jun39"
   ]));	 
}