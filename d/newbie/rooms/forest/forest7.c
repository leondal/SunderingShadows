//forest7.c entrance to bugbear lair

#include "../../newbie.h"
#include "forest.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",1);
   set_property("no teleport",1);
   set_short("%^ORANGE%^Downhill slope%^RESET%^");
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
   set_long(
@STYX
The thorny bushes are still thick on all sides here, but a path has been carved out continuing eastward down a steep hill.  The trees block much of the light, especially as you get further down the hill.  This path appears to lead to a cave opening.
STYX
   );
   set_smell("default","You catch a definite stench of something unpleasant.");
   set_listen("default","The dense undergrowth seems to absorb most sounds.");
   set_items( ([ "bushes": "The stretches of thick thorny bushes and vines block passage except to the east and west.", 
      "path":"%^ORANGE%^A path has been hacked through the bushes.%^RESET%^", 
	({"vines", "trees"}):"%^GREEN%^The trees and bushes are heavily entwined with heavy vines.%^RESET%^" ]) );
	set_exits(([
      "west":FOREST"forest6",
      "east":FOREST"forest8",
   ]));
}
