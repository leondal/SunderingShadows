//stairs1

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(STAIRWAY);
     set_properties((["indoors":1,"light":1]));
   set_short("Staircase in the monastery");
   set_long(
@OLI
   This is a long winding stone staircase. Here at the
base you see it wind up into the distance. The long deep
stone steps have started to decay, but it will take
many eons to destroy these monstrous steps.

For now you don't seem to be able to climb them.
OLI
   );
   set_smell("default","The old stone has kept all of the smells it's been exposed to.");
   set_listen("default","You heartbeat echos in the distance.");
   set_exits(([
      "northwest":MONASTERY+"hall1",
   ]));
}
