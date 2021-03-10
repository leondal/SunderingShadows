//forest6.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
   ::create();
   set_long(""+TO->query_long()+"  %^GREEN%^The vines and bushes to the east look a little odd."); 
	set_items( ([ "bushes": "%^ORANGE%^The thorny bushes block passage here and there, but appear to have been broken through to the east here.", 
	({"vines", "trees"}):"%^GREEN%^On closer inspection, you see some of the vines have been cut but left hanging to appear to block the east.  Perhaps you can go east after all.%^RESET%^" ]) );
    set_exits(([
      "west":FOREST"forest5",
      "east":FOREST"forest7",
      "southwest":FOREST"forest13",
      "south":FOREST"forest14",
      "southeast":FOREST"forest15",
   ]));
   set_invis_exits(([ 
   	  "east":FOREST"forest7", 
   ]));
}
