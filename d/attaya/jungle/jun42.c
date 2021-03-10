//Octothorpe (4/21/13)
//Attaya Jungle Path 42
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun40",
     "west":JGL"jun41",
     "east":JGL"jun43",
   ]));	 
}