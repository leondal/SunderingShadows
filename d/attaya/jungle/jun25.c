//Octothorpe (3/26/10)
//Attaya Jungle Path 25
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "east":JGL"jun26",
     "north":JGL"jun24",
   ]));	 
}