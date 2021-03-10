//k_road.c - Inherit for road to the new Koenig - coded by Circe 10/3/03
#include <std.h>
#include "../koenig.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set_name("An old abandoned road");
   set_short("An old abandoned road");
   set_long(
      "This narrow roadway leads deeper into the Quiet Forest.  "+
      "While most of forest is pleasantly still, this section "+
      "has an oppressive, eerie air that suggests "+
      "all is not well here.  The trees press close to the deserted "+
      "road, their full branches hanging not far overhead."+
      "\n");
   set_smell("default","The underlying fragrance of wildflowers is masked by the scent of decay.");
   set_listen("default","The only sounds are those you make.  Not even a bird sings here.");
   set_items(([
      ({"road","roadway","road way"}) : "The narrow road looks to have been a "+
         "neatly-blazed dirt road at one time.  Now it has fallen into disrepair "+
         "and is little more than a trail.",
      ({"forest","trees","tree","woods"}) : "The trees of the forest tower overhead.  "+
         "This is a temperate forest and has a mixture of large oaks, elms, and cypress "+
         "dwarfed by even taller evergreens.",
      ({"branch","branches"}) : "The thick branches of the trees form a canopy overhead, "+
         "offering protection from the elements and giving the forest an oppressive feel."
   ]));
}