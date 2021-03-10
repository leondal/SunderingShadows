#include <std.h>
#include "../outpost.h"

inherit STORAGE"coastline";

void create(){
   ::create();
   set_exits(([
      "south" : "d/laerad/wasteland/waste2",
      "northeast" : ROOMS"2",
   ]));
}
void reset(){
	::reset();
	if(!present("anton")){new(MOBS"anton")->move(TO);}
	if(!present("gateguard")){new(MOBS"gateguard")->move(TO);}
	
}