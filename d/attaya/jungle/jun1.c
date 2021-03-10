//Octothorpe (3/22/10)
//Attaya Jungle Path 1
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "northeast":JGL"jun2",
     "southwest":"/d/attaya/beach9"
   ]));	 
}