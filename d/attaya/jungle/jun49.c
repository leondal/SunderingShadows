//Octothorpe (4/23/13)
//Attaya Jungle Path 49
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun55",
     "west":JGL"jun48",
   ]));	 
}