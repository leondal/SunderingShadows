//Octothorpe (4/23/13)
//Attaya Jungle Path 57
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun56",
     "east":JGL"jun58",
   ]));	 
}