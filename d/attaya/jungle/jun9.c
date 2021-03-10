//Octothorpe (3/26/10)
//Attaya Jungle Path 9
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun55",
     "west":JGL"jun10",
	 "east":JGL"jun8"
   ]));	 
}