//ptrail21.c
#include "../kildare.h"

inherit PTRAIL;
void create(){
   ::create();
   set_long(
      "The %^ORANGE%^rubble-strewn trail %^RESET%^snakes its way up the %^GREEN%^mountainside%^RESET%^, twisting "+
      "and slithering into the shadows of %^GREEN%^dying evergreens%^RESET%^.  Drying limbs "+
      "click and creak on the wind, creating eerie sounds and %^BOLD%^%^BLACK%^shadows%^RESET%^.  The "+
      "%^YELLOW%^debris %^RESET%^covering the %^ORANGE%^path %^RESET%^shifts with the wind, making footing treacherous. "+
      " Down the mountainside, faint signs of civilization are visible.  A %^BOLD%^%^BLACK%^wisp of "+
      "smoke %^RESET%^rises into the air, hinting at the comfort of indoors, though it only "+
      "serves to emphasize the desolation of the trails here higher up in the mountains."+
      "The trail seems to end here, with the rock wall of the "+
      "%^GREEN%^mountainside %^RESET%^rising sharply to the north and blocking the path."+
      "\n"
   );
   set("night long",
      "%^BLUE%^The twisted shapes of the bare %^GREEN%^evergreens %^BLUE%^create disconcerting %^BOLD%^%^BLACK%^shadows "+
      "%^RESET%^%^BLUE%^against the night sky.  Skeletal limbs blacker than midnight wave in the air, adding a "+
      "strange sort of dance to the sorrowful dirge of their creaks and groans .  No %^YELLOW%^stars "+
      "%^RESET%^%^BLUE%^seem to shine here, leaving the mountainside bathed in abyssal darkness.  Footing is "+
      "uncertain, with the broken %^ORANGE%^rocks %^BLUE%^of the mountain breaking free and shifting almost "+
      "of their own accord.  No signs of civilization can be found in any direction, and "+
      "it is nearly impossible to tell where the %^WHITE%^trail %^BLUE%^may lead.  The %^GREEN%^mountainside "+
      "%^BLUE%^rises high to the north suddenly, blocking the way and forming a deep "+
      "black shadow between the trees."+
      "\n"
   );
   add_item("mountainside","The mountain rises sharply to the "+
         "north, though perhaps not quite as sheer as it seems at first.  A "+
         "few cracks and tiny outcroppings suggest that you might be able to climb it.");
   add_item("mountain","The mountain rises sharply to the "+
         "north, though perhaps not quite as sheer as it seems at first.  A "+
         "few cracks and tiny outcroppings suggest that you might be able to climb it.");
   add_item("wall","The mountain rises sharply to the "+
         "north, though perhaps not quite as sheer as it seems at first.  A "+
         "few cracks and tiny outcroppings suggest that you might be able to climb it.");
   set_exits(([
      "west" : ROOMS"ptrail20",
      ]));
   set_climb_exits(([
      "climb":({ROOMS"nest2",10,4,100}),
      ]));
   set_fall_desc("You lose your grip on the slippery rocks and fall back to rubble-strewn ground!");
}