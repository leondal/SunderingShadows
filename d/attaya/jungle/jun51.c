//Octothorpe (4/23/13)
//Attaya Jungle Path 51
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun13",
     "west":JGL"jun50",
     "east":JGL"jun52",
   ]));	 
}