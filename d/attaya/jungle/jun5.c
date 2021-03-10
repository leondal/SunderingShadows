//Octothorpe (3/22/10)
//Attaya Jungle Path 5
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "north":JGL"jun6",
     "west":JGL"jun4",
   ]));	 
}