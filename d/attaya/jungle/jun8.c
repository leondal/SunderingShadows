//Octothorpe (3/26/10)
//Attaya Jungle Path 8
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "south":JGL"jun7",
     "west":JGL"jun9",
   ]));	 
}