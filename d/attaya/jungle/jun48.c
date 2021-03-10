//Octothorpe (4/23/13)
//Attaya Jungle Path 48
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "northeast":JGL"jun55",
     "west":JGL"jun47",
     "east":JGL"jun49",
   ]));	 
}