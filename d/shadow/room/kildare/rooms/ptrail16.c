//ptrail16.c
#include <std.h>
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
      "The %^GREEN%^mountainside %^RESET%^rises high to the east here, though there "+
      "does not seem to be a way to climb up."+
      "\n"
   );
   set("night_long",
      "%^BLUE%^The twisted shapes of the bare %^GREEN%^evergreens %^BLUE%^create disconcerting %^BOLD%^%^BLACK%^shadows "+
      "%^RESET%^%^BLUE%^against the night sky.  Skeletal limbs blacker than midnight wave in the air, adding a "+
      "strange sort of dance to the sorrowful dirge of their creaks and groans .  No %^YELLOW%^stars "+
      "%^RESET%^%^BLUE%^seem to shine here, leaving the mountainside bathed in abyssal darkness.  Footing is "+
      "uncertain, with the broken %^ORANGE%^rocks %^BLUE%^of the mountain breaking free and shifting almost "+
      "of their own accord.  No signs of civilization can be found in any direction, and "+
      "it is nearly impossible to tell where the %^WHITE%^trail %^BLUE%^may lead."+
      "The %^GREEN%^mountainside %^BLUE%^rises "+
      "high to the east here, though there does not seem to be a way to climb up.%^RESET%^"+
      "\n"
   );
   add_item("mountainside","The mountain rises sharply to the east, creating a high "+
      "mound.  There does not seem to be a way up from here.");
   set_exits(([
      "southeast" : ROOMS"ptrail13",
      "northeast" : ROOMS"ptrail15"
      ]));
}
