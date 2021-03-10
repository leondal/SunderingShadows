//Octothorpe (3/22/10)
//Attaya Jungle Path 4
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun3",
     "southeast":JGL"jun39",
     "east":JGL"jun5"
   ]));	 
}