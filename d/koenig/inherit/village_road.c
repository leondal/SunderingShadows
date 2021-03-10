//village_road.c - inherit for the road through Koenig Village.  Coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_name("An abandoned village road");
   set_short("An abandoned village road");
   set_smell("default","A strange charred scent rises on the wind.");
   set_listen("default","The only sounds are those you make.  Not even a bird sings here.");
   set_items(([
      ({"road","roadway","road way"}) : "The narrow road looks to have been a "+
         "neatly-blazed dirt road through the village at one time.  Now it has fallen into disrepair "+
         "and is little more than a trail.",
      ({"forest","trees","tree","woods"}) : "The trees of the forest tower all around the village.  "+
         "The woods are a temperate forest and have a mixture of large oaks, elms, and cypress "+
         "dwarfed by even taller evergreens.",
      ({"village","town"}) : "The ramshackle buildings of the village line the road through "+
         "the town.  Most have holes in the roof and are missing windows.  Some great destruction "+
         "must have ravaged this place to leave it in ruins like this."
   ]));
}
