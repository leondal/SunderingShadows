//Octothorpe (4/23/13)
//Attaya Jungle Path 59
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun58",
   ]));	 
}