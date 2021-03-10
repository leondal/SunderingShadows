//ptrails.c
#include <std.h>
#include "../kildare.h"

inherit "/std/controlroom.c";
void create(){
   switch(random(10)) {
      case 0: break;
      case 1: set_monsters( ({MON"peryton"}),({1+random(2)}));
              break;
      case 2: set_monsters( ({MON"peryfem"}),({random(3)+1}));
              break;
      case 3: set_monsters( ({MON"peryton",MON"peryfem"}),({random(2),1+random(2)}));
              break;
      case 4..5: set_monsters( ({MON"peryton"}),({1}));
              break;
      default:  break;
   }
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_repop(35);
   set_name("Mountain Trail");
   set_short("A twisting mountain trail");
   set_long(
      "The %^ORANGE%^rubble-strewn trail %^RESET%^snakes its way up the %^GREEN%^mountainside%^RESET%^, twisting "+
      "and slithering into the shadows of %^GREEN%^dying evergreens%^RESET%^.  Drying limbs "+
      "click and creak on the wind, creating eerie sounds and %^BOLD%^%^BLACK%^shadows%^RESET%^.  The "+
      "%^YELLOW%^debris %^RESET%^covering the %^ORANGE%^path %^RESET%^shifts with the wind, making footing treacherous. "+
      " Down the mountainside, faint signs of civilization are visible.  A %^BOLD%^%^BLACK%^wisp of "+
      "smoke %^RESET%^rises into the air, hinting at the comfort of indoors, though it only "+
      "serves to emphasize the desolation of the trails here higher up in the mountains."+
      "\n"
      );
   set("night long",
      "%^BLUE%^The twisted shapes of the bare %^GREEN%^evergreens %^BLUE%^create disconcerting %^BOLD%^%^BLACK%^shadows "+
      "%^RESET%^%^BLUE%^against the night sky.  Skeletal limbs blacker than midnight wave in the air, adding a "+
      "strange sort of dance to the sorrowful dirge of their creaks and groans.  No %^YELLOW%^stars "+
      "%^RESET%^%^BLUE%^seem to shine here, leaving the mountainside bathed in abyssal darkness.  Footing is "+
      "uncertain, with the broken %^ORANGE%^rocks %^BLUE%^of the mountain breaking free and shifting almost "+
      "of their own accord.  No signs of civilization can be found in any direction, and "+
      "it is nearly impossible to tell where the %^WHITE%^trail %^BLUE%^may lead."+
      "\n"
   );
   set_smell("default","A strange scent of decay hangs in the air.");
   set_listen("default","Screeches and roars battle against the buffeting wind.");
   set_items(([
      "trail" : "What little trail there is has been covered with rocks and rubble, "+
         "making travel difficult.  It twists and winds around the mountainside, leading "+
         "through dying evergreen trees.  It is difficult to see very far in any direction.",
      (({"evergreen","evergreens","trees","limbs"})) : "The drying limbs of the trees seem "+
         "almost to be skeletal arms reaching up into the sky.  The wood is blackened and "+
         "has an unnatural look, as if some sort of blight has plagued this land.",
      (({"rock","broken rock","rubble","rocks","debris"})) : "Broken and jagged stones line the path, "+
         "making the journey difficult.  The rubble seems to have been caused by a rockslide "+
         "of sorts, judging by long streak marks down the side of the mountain.  Some of the "+
         "piles of rubble still look a little unstable."
   ]));

}

void reset() {
/*
   int active;
   active = has_mobs();
   if(!active) {
      if(mons)  mons = ([]);
      switch(random(4)) {
         case 0..1: break;
         case 2: set_monsters( ({MON"peryton"}),({1}));
                 break;
         case 3: set_monsters( ({MON"peryfem",MON"peryton"}),({2,1}));
                 break;
      }
   }
*/
   ::reset();
}
