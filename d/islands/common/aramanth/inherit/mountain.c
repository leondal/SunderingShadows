#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_property("light",3);
   set_property("no teleport", 1);
   set_property("indoors",0);
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
   set_short("You are on a mountain.");
   set_items(([
      "ground" : "There is a clear path running along the side of this forested mountain.",
      "forest" : "The trees are thick near the base of the mountain, but become scarce the further up you go.",
   "mountain" : "The mountain is large and intimidating. There are jagged cliffs here and there, but strangely enough the ground contains a path all the way to the top."
   ]));
}
