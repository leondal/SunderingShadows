//k_road07.c - Leading to the new village of Koenig - coded by Circe 10/3/03
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
      "%^BOLD%^%^GREEN%^This %^BLACK%^na%^RESET%^rr%^BOLD%^o%^BLACK%^w r%^WHITE%^oa%^RESET%^dw%^BOLD%^%^BLACK%^ay %^GREEN%^leads deeper into the %^RESET%^%^CYAN%^Quiet Forest%^BOLD%^%^GREEN%^. The forest closes in %^RESET%^%^CYAN%^oppressively %^BOLD%^%^GREEN%^in all directions except for a %^RESET%^%^ORANGE%^narrow pathway %^BOLD%^%^GREEN%^winding through the tree trunks to the west, and the %^RESET%^%^ORANGE%^broken road %^BOLD%^%^GREEN%^leading to the village just south of here. Though this looks to have once been a %^CYAN%^peaceful village %^GREEN%^of loggers, it has been %^RESET%^%^CYAN%^ravaged %^BOLD%^%^GREEN%^and left %^RESET%^%^CYAN%^abandoned%^BOLD%^%^GREEN%^. Several small %^RED%^buildings %^GREEN%^stand in relief against the forest to the south.%^RESET%^"+
      "\n");
   set_smell("default","A strange charred scent rises on the wind.");
   set_listen("default","The only sounds are those you make.  Not even a bird sings here.");
   set_items(([
      ({"road","roadway","road way"}) : "The narrow road looks to have been a "+
         "neatly-blazed dirt road at one time.  Now it has fallen into disrepair "+
         "and is little more than a trail.",
      ({"forest","trees","tree","woods"}) : "The trees of the forest tower overhead.  "+
         "This is a temperate forest and has a mixture of large oaks, elms, and cypress "+
         "dwarfed by even taller evergreens.",
      ({"branch","branches"}) : "The thick branches of the trees form a canopy overhead, "+
         "offering protection from the elements and giving the forest an oppressive feel.",
      ({"building","buildings"}) : "The thatch rooftops of the village to the south look "+
         "as though they were burned sometime in the past.  The buildings still stand and "+
         "seem somewhat solid, but you can see holes in the roof.  Surely no one lives "+
         "here now."
   ]));
   set_exits(([
      "west" : VILROOMS"k_road06",
      "south" : VILROOMS"k_road08"
   ]));
}