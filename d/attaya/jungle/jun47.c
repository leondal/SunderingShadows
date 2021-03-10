//Octothorpe (4/23/13)
//Attaya Jungle Path 47
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun53",
     "west":JGL"jun46",
     "east":JGL"jun48",
   ]));	 
}