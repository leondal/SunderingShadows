//Octothorpe (3/26/10)
//Attaya Jungle Path 18
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
//"north":JGL"jun63",

     "south":JGL"jun58",
	 "west":JGL"jun17",
	 "east":JGL"jun19"
   ]));	 
}
