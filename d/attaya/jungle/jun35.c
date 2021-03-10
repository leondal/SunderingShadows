//Octothorpe (3/22/10)
//Attaya Jungle Path 35
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun36",
     "west":JGL"jun34",
   ]));	 
}