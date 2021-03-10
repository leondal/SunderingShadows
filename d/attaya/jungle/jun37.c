//Octothorpe (4/21/13)
//Attaya Jungle Path 37
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun3",
     "east":JGL"jun38"
   ]));	 
}