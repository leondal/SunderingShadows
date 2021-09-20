
//Jarmila Hill - tentcity.c - LoKi - 2021
// Base of the Hill Celabratory Tent City


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
   set_name("colorful tent city");
   set_short("%^BOLD%^c%^RED%^o%^WHITE%^l%^MAGENTA%^o%^WHITE%^"+
   "r%^GREEN%^f%^WHITE%^ul t%^ORANGE%^e%^WHITE%^n%^BLUE%^t "+
   "%^WHITE%^ci%^MAGENTA%^t%^WHITE%^y%^RESET%^");
   set_long("%^ORANGE%^The area around the base of the %^BOLD%^hill "+
   "%^RESET%^%^ORANGE%^is in the midst of what could only be described "+
   "as a %^BOLD%^%^MAGENTA%^celebration%^RESET%^%^ORANGE%^. Tents of "+
   "all %^BOLD%^%^CYAN%^shapes%^RESET%^%^ORANGE%^, %^MAGENTA%^sizes "+
   "%^ORANGE%^and %^BOLD%^%^RED%^colors %^RESET%^%^ORANGE%^occupy "+
   "every square inch of ground and between revelers and curious "+
   "folk gather, dance, and sing. %^BOLD%^%^WHITE%^Flags %^RESET%^"+
   "%^ORANGE%^and %^BOLD%^streamers %^RESET%^%^ORANGE%^flap in the "+
   "wind and the aroma of %^BOLD%^%^MAGENTA%^exotic cooking "+
   "%^RESET%^%^ORANGE%^fills the air. Far above you on the hill a "+
   "%^BOLD%^great golden glow %^RESET%^%^ORANGE%^framing the crags "+
   "above even brighter than the %^BOLD%^sun %^RESET%^%^ORANGE%^above "+
   "you. The ground has been %^BOLD%^%^BLACK%^compacted %^RESET%^"+
   "%^ORANGE%^with the feet of thousands who have flocked here. "+
   "What is strange is that for all of the people, there is "+
   "only %^BOLD%^%^CYAN%^joy %^RESET%^%^ORANGE%^in the air.%^WHITE%^\n");
  
   set_items(([
      ({"tent","tents"}) : "Everywhere you look someone has put up a tent. They "+
	  "range from small one person lean tos, to massive party tents capable of "+
	  "holding hundreds of revelers. YOu hear the sounds of laughter and "+
	  "singing from every corner.%^RESET%^",
	  ({"ground","compacted ground"}) : "%^RESET%^%^ORANGE%^The ground has "+
	  "been compacted so much from people walking that it is as hard and easy "+
	  "to travese as any road, though there is no way anyone could take a "+
	  "wagon through here with how cramped it is.%^RESET%^",
	  ({"glow","golden glow"}) : "%^YELLOW%^from above you a golden glow "+
	  "radiates from the top of the hill. A normal light this bright would "+
	  "hurt to look at but as you do, all you can feel is peace and comfort.%^RESET%^",
      ({"flags","banners","lanterns","streamers"}) : "%^BOLD%^All around you "+
	  "streamers, flags and banners of a thousand different colors fly, "+
	  "lending to the feeling you are in a celebration%^RESET%^",
	  ]));
	  
   set_listen("default","You hear the sounds of revelry and dancing");
   set_smell("default","You smell exotic spices and cooking");
	  
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
