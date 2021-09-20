
//Jarmila Hill - military.c - LoKi - 2021
// Military Tent City


#include <std.h>
#include "../jarmila.h"

inherit CROOM;
void pick_critters();


void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_climate("temperate");
   set_property("light", 2);
   set_name("quiet tent encampment");
   set_short("quiet tent encampment");
   set_long("%^BOLD%^%^BLACK%^The chaotic %^BLUE%^sea %^BLACK%^of "+
   "%^RESET%^%^ORANGE%^tents %^BOLD%^%^BLACK%^peters out as you "+
   "climb the base of the hill. Here there are less %^RESET%^"+
   "%^MAGENTA%^merchants %^BOLD%^%^BLACK%^and %^CYAN%^revelers "+
   "%^BLACK%^and instead you find orderly %^WHITE%^military style "+
   "%^RESET%^%^ORANGE%^tents %^BOLD%^%^BLACK%^inter spaced with "+
   "those of dignitaries. Small groups of %^RESET%^Templar "+
   "%^BOLD%^%^BLACK%^wander through the %^RESET%^%^ORANGE%^"+
   "tents%^BOLD%^%^BLACK%^, keeping the revelers from traveling "+
   "further up the hill. The %^RESET%^%^ORANGE%^tents %^BOLD%^%^BLACK%^"+
   "themselves are set up with space between them and there are even "+
   "%^RESET%^%^ORANGE%^barricades %^BOLD%^%^BLACK%^set up on the path. "+
   "The %^ORANGE%^glow %^BLACK%^from the top of the hill is still on "+
   "full display.%^RESET%^%^RESET%^\n");
  
   set_items(([
      ({"tent","tents"}) : "%^RESET%^%^ORANGE%^The tents along the "+
	  "path have been arranged with precision and planning. Each bears "+
	  "a flag of what faction or government they represent. Less revelry "+
	  "and celebration sounds from inside but it is not gone entirely.",
      ({"barricade","barricades"}) : "%^RESET%^%^ORANGE%^Across the "+
	  "pathway at several points are heavy barricades. They are made "+
	  "of heavy oak and have been placed there intentionally but have "+
	  "been decorated in such a way that most would think they were just "+
	  "part of the larger celebration. Obviously some military planning "+
	  "is going on here.%^RESET%^",
	  ({"ground","compacted ground"}) : "%^RESET%^%^ORANGE%^Th ground has "+
	  "been compacted so much from people walking that it is as hard and easy "+
	  "to traverse as any road, though there is no way anyone could take a "+
	  "wagon through here with how cramped it is.%^RESET%^",
	  ({"glow","golden glow"}) : "%^YELLOW%^from above you a golden glow "+
	  "radiates from the top of the hill. A normal light this bright would "+
	  "hurt to look at but as you do, all you can feel is peace and comfort.%^RESET%^",
	  ]));
	  
   set_listen("default","You hear the faint sounds of revelry and dancing");
   set_smell("default","You faintly smell exotic spices and cooking");
	  
}

void reset() {
   int active;
   active = has_mobs();

   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();
}


void pick_critters(){
   switch(random(7)){
      case 0..3: break;
      case 4:  set_monsters( ({MOBS"rev3"}),({1}) );
               break;
      case 5:  set_monsters( ({MOBS"rev2"}),({1}) );
               break;
      case 6:  set_monsters( ({MOBS"rev1"}),({1}) );
               break;
}
}
