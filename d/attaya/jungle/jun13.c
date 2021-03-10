//Octothorpe (3/26/10)
//Attaya Jungle Path 13
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun14",
     "south":JGL"jun51",
	 "east":JGL"jun12"
   ]));	 
}