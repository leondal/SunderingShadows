//Octothorpe (2/1/17)
//Shadow, Mage Tower Gazebo
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Inside the Gazebo");
   set_short("%^BOLD%^%^WHITE%^Inside the Gazebo%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Inside the Gazebo%^RESET%^\n"+
      "%^BOLD%^%^WHITE%^In the gazebo, you feel a sense of %^MAGENTA%^"+
      "peace %^WHITE%^as you watch %^RESET%^r%^BOLD%^o%^RESET%^se "+
      "pet%^BOLD%^a%^RESET%^ls %^BOLD%^dance upon a playful breeze, "+
      "and listen to the soft %^CYAN%^s%^RESET%^%^CYAN%^p%^BOLD%^la"+
      "%^RESET%^%^CYAN%^s%^BOLD%^h %^WHITE%^of the surrounding fountains. "+
      "The gazebo looks very %^RESET%^old %^BOLD%^from this side, "+
      "although well maintained. Stone benches are arranged along the "+
      "perimeter. The seats are smooth and white, and the legs carved "+
      "into effigies of strange and mythical beings. The benches all "+
      "face a small shrine that is arranged here in devotion to "+
      "%^MAGENTA%^Kismet, the Lady of Mysteries%^WHITE%^. %^BLACK%^"+
      "Cracks %^WHITE%^have begun to creep along the surface of "+
      "everything, and %^GREEN%^m%^RESET%^%^GREEN%^o%^BOLD%^ss "+
      "%^WHITE%^has settled into every crevice.%^RESET%^\n");
   set_smell("default","%^GREEN%^The scent of cloves lingers in the "+
      "air.%^RESET%^");
   set_listen("default","%^BOLD%^%^CYAN%^The splashing of the fountains "+
      "is relaxing.%^RESET%^");
   set_items(([
      ({"vines","roses"}) : "%^RESET%^Oddly the %^BOLD%^roses %^RESET%^"+
         "seem to have sprouted from the top of the gazebo and now "+
         "tumble down along the %^BOLD%^white panels %^RESET%^and creep "+
         "along the %^BOLD%^columns%^RESET%^, while some are left to "+
         "swing freely. Their %^BOLD%^white petals %^RESET%^grace the "+
         "surface of the pool and dance endlessly upon the "+
         "%^BOLD%^%^CYAN%^breeze%^RESET%^.",
      ({"pool","stairs","fountains"}) : "%^RESET%^Eight stairs lead "+
         "up to this formidable %^BOLD%^%^CYAN%^pool%^RESET%^. The "+
         "water is impressively clear, yet peering down you can see no "+
         "end to it, only %^BOLD%^%^BLACK%^darkness%^RESET%^. The water "+
         "ripples gently as petals from the overhanging %^BOLD%^blossoms "+
         "%^RESET%^lightly land on its surface. Colorful %^BOLD%^"+
         "%^MAGENTA%^koi fish %^RESET%^swim gracefully through the "+
         "clean water. Marking the cardinal directions, four %^BOLD%^"+
         "%^BLUE%^spouts %^RESET%^of water rise and fall, at times "+
         "catching the light just right and casting off %^BOLD%^"+
         "%^GREEN%^r%^RESET%^%^GREEN%^a%^CYAN%^i%^BOLD%^n%^BLUE%^b"+
         "%^RESET%^%^BLUE%^o%^MAGENTA%^w%^BOLD%^s%^RESET%^.",
      "benches" : "%^RESET%^Stone benches are arranged along the "+
         "perimeter. The seats are smooth and %^BOLD%^white%^RESET%^, "+
         "and the legs carved into effigies of %^MAGENTA%^strange "+
         "beasts %^WHITE%^and %^MAGENTA%^mythical beings%^WHITE%^. The "+
         "benches all face a %^BOLD%^small shrine %^RESET%^that is "+
         "arranged here in devotion to %^BOLD%^%^MAGENTA%^Mystra, the "+
         "Lady of Mysteries%^RESET%^. %^BOLD%^%^BLACK%^Cracks %^RESET%^"+
         "have begun to creep along the surface of everything, and "+
         "%^BOLD%^%^GREEN%^moss %^RESET%^has settled into every crevice.",
      "shrine" : "%^RESET%^The Goddess is shown here with one knee "+
         "on the ground and a palm lifted in the air as if on the cusp "+
         "of casting a %^BOLD%^%^BLUE%^spell%^RESET%^. The statue shows "+
         "signs of wear, its details fading from centuries of "+
         "worshippers laying their hands on the stone surface. %^BOLD%^"+
         "Candles %^RESET%^and %^BOLD%^%^GREEN%^flowers %^RESET%^are "+
         "strewn about the base of the statue, each one somebody's prayer "+
         "to the %^BOLD%^%^MAGENTA%^Mother of Mysteries%^RESET%^.",
      ({"cracks","moss"}) : "%^BOLD%^%^BLACK%^Cracks %^RESET%^have "+
         "begun to creep along the surface of everything, and "+
         "%^BOLD%^%^GREEN%^moss %^RESET%^has settled into every crevice."
   ]));
   set_exits(([
      "out" : ROOMS"magecourt"
   ]));
}