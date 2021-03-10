//ptrail22.c
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
      "To the west, the mountainside seems to have been carved out "+
      "sometime in the past.  What looks to be a %^BOLD%^%^BLACK%^rock quarry %^RESET%^fills a tiny valley "+
      "there, with the large %^BLUE%^boulders %^RESET%^and smaller %^ORANGE%^stones %^RESET%^littering the ground."+
      "\n"
   );
   set("night long",
      "%^BLUE%^The twisted shapes of the bare %^GREEN%^evergreens %^BLUE%^create disconcerting %^BOLD%^%^BLACK%^shadows "+
      "%^RESET%^%^BLUE%^against the night sky.  Skeletal limbs blacker than midnight wave in the air, adding a "+
      "strange sort of dance to the sorrowful dirge of their creaks and groans .  No %^YELLOW%^stars "+
      "%^RESET%^%^BLUE%^seem to shine here, leaving the mountainside bathed in abyssal darkness.  Footing is "+
      "uncertain, with the broken %^ORANGE%^rocks %^BLUE%^of the mountain breaking free and shifting almost "+
      "of their own accord.  No signs of civilization can be found in any direction, and "+
      "it is nearly impossible to tell where the %^WHITE%^trail %^BLUE%^may lead."+
      "To the west, a small %^GREEN%^valley %^BLUE%^is carved into the mountainside.  "+
      "%^BOLD%^%^BLACK%^Boulders %^RESET%^%^BLUE%^and other rubble "+
      "block the way there, and it's hard to tell exactly what it may be at night."+
      "\n"
   );
   add_item("quarry","The small sliver of a valley to the west is filled "+
         "with rocks from the now-abandoned quarry.  It seems to have been "+
         "quite active at one time in the past, but now lies dormant.  Perhaps "+
         "something has forced the villagers to stay indoors.");
   add_item("valley","The small sliver of a valley to the west is filled "+
         "with rocks from the now-abandoned quarry.  It seems to have been "+
         "quite active at one time in the past, but now lies dormant.  Perhaps "+
         "something has forced the villagers to stay indoors.");
   add_item("boulders","Large boulders partially block the view into the valley.");
   set_exits(([
      "south" : ROOMS"ptrail23",
      "northeast" : ROOMS"ptrail20"
      ]));
}
