//efroad2.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_short("A trail through the forest");
   set_long("%^RESET%^%^GREEN%^A trail through the forest\nYou are on a trail through a thick and forboding forest.  "+
   "The trail is composed of %^RESET%^%^ORANGE%^dirt%^RESET%^%^GREEN%^ that has been "+
   "hardened and packed down from years of frequent use.  The forest surrounding you "+
   "is so overgrown as to be completely impassable beyond the limited range of the trail.  Many "+
   "of the trees look ancient and shoot upwards for several hundred feet.  Smaller new growth "+
   "occupies the spaces between the larger trees, forming a natural wall around "+
   "this trail.  "+
   "You have no idea what type of creatures might call it home but "+
   "you believe that as long as you remain on the trail you will be safe from whatever "+
   "they might be.%^RESET%^");
   
   set_smell("default","\nThe smell of the forest mixes with the fragrance of civilation.");
   set_listen("default","You hear the sound of the wind in the trees.");

   set_items(([
       "trail":"The dirt is hard-packed beneath your feet.",
       ({"trees","newgrowth", "wall", "forest"}): "%^BOLD%^%^GREEN%^The forest is surrounding you "+
       "is composed of ancient and gigantic trees which shoot up several hundred feet into the air. There "+
       "are multitudes of smaller new growth occupying all the available spaces between the larger trees, "+
       "effectively creating a natural wall around the trail.%^RESET%^",
   ]));
}
