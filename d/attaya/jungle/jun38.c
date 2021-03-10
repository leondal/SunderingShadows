//Octothorpe (4/21/13)
//Attaya Jungle Path 38
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun37",
     "east":JGL"jun39",
   ]));	 
}