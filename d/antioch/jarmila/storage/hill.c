//Jarmila Hill - military.c - LoKi - 2021
// The Hill


#include <std.h>
#include "../jarmila.h"

inherit CROOM;
void pick_critters();


void create(){
   ::create();
   set_terrain(GRASSLANDS);
   set_travel(GAME_TRACK);
   set_climate("temperate");
   set_property("light", 2);
   set_property("no pocket space",1);
   set_name("narrow path on the hill");
   set_short("%^C046%^narrow %^C058%^path%^C046%^ "+
   "on the hill%^CRST%^");
   set_long("%^C046%^stretching around the hill, "+
   "this %^C058%^path%^C046%^ is narrow and "+
   "%^C254%^rocky%^C046%^. It was obviously a "+
   "%^C136%^game trail%^C046%^ that has been "+
   "expanded by those who have gone up and down "+
   "the hill because of the %^C226%^glow%^C046%^. "+
   "Far below you you can still see the %^C091%^tent city%^C046%^ "+
   "sprawling though from here you cannot hear any "+
   "of the %^C198%^revelry%^C046%^. On either side of "+
   "the %^C058%^trail%^C046%^ conifer trees cling to "+
   "the %^C254%^rocks%^C046%^, hardy and healthy. The "+
   "%^C190%^glow%^C046%^ here is ever present.%^CRST%^\n");

   set_items(([
      ({"trees","rocks"}) : "%^C046%^conifer trees line the "+
	  "sides of the path and grow between the rocks.%^CRST%^",
      ({"ground","trail"}) : "%^C058%^The trail winds up and "+
	  "down the hill, narrow but safe to walk.%^CRST%^",
      ({"glow","golden glow"}) : "%^C226%^The glow here is ever "+
	  "present and continues to fill you with joy and comfort.%^CRST%^",
	  ({"camp","tent city"}) : "%^C091%^Far below you you can "+
	  "see the tent city filled with the revelers and devout. "+
	  "From here you can almost pick out individual tents but "+
	  "at this distance you cannot see people or hear any of "+
	  "the music.%^CRST%^",
          ]));

   set_listen("default","You hear the wind and distant birds");
   set_smell("default","You smell conifers and rich earth");

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
      case 4:  set_monsters( ({MOBS"foo"}),({random(9) }) );
               break;
      case 5:  set_monsters( ({MOBS"foo"}),({random(3) }) );
               break;
      case 6:  set_monsters( ({MOBS"foo"}),({random(5) }) );

               break;
}
}

