//Copy of temple for Newbietown

#include "../../newbie.h"
#include <std.h>

inherit "/d/newbie/rooms/temples/cyric_inh";

void create(){
   ::create();
	set_property("no teleport",1);
   set_exits(([
      "out": MAINTOWN"portals"
   ]));
}

void reset(){
   ::reset();
   if(!present("npc cleric")) new(TEMPLENPC"p_cyric")->move(TO);
}
