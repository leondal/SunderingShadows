//Octothorpe (2/1/17)
//Three Coins Inn Courtyard
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
   set_name("The Courtyard, Three Coins Inn, Shadow");
   set_short("%^BOLD%^%^WHITE%^The Courtyard, Three Coins Inn, "+
      "Shadow%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^The Courtyard, Three Coins Inn, "+
      "Shadow%^RESET%^\n"+
      "%^BOLD%^%^BLACK%^This outdoor courtyard looks like a comfortable "+
      "area to relax and enjoy the open air. %^GREEN%^Ivy %^BLACK%^"+
      "creeps along the walls and stone %^RESET%^archways %^BOLD%^"+
      "%^BLACK%^that lead off to the left or right. Beyond the archways, "+
      "staircases with %^RESET%^%^ORANGE%^wooden railings %^BOLD%^%^BLACK%^"+
      "lead to the next level balcony from which guests can find their "+
      "rooms. Some %^RESET%^wicker chairs %^BOLD%^%^BLACK%^have been "+
      "set up for lounging, and the decor is simple but elegant. A nice "+
      "%^RESET%^%^CYAN%^rug %^BOLD%^%^BLACK%^covers the tile floor."+
      "%^RESET%^\n\n"+
      "%^CYAN%^A small sign hanging on the wall indicates that guest "+
      "rooms can be found on the next level, while food, drinks and "+
      "entertainment are found on the top floor.%^RESET%^\n");
   set_smell("default","%^GREEN%^The faint scents of %^BOLD%^food "+
      "%^RESET%^%^GREEN%^and %^BOLD%^flowers %^RESET%^%^GREEN%^mingle "+
      "here.%^RESET%^");
   set_listen("default","%^RESET%^The soft %^BOLD%^murmur %^RESET%^of "+
      "conversation fills the courtyard.%^RESET%^");
   set_items(([
      "ivy" : "%^RESET%^%^GREEN%^Green %^BOLD%^ivy %^RESET%^%^GREEN%^"+
         "climbs up the stone walls, adding a pleasing touch of color "+
         "to the light stones.%^RESET%^",
      ({"steps","balcony","archways"}) : "%^RESET%^%^GREEN%^Through the "+
         "%^BOLD%^ivy-covered %^RESET%^%^GREEN%^archways and up the stairs "+
         "is a sturdy balcony. You can see %^BOLD%^doors %^RESET%^%^GREEN%^"+
         "lining the balcony, which must give access to the guest "+
         "rooms.%^RESET%^",
      ({"walls","lanterns"}) : "%^RESET%^%^BOLD%^%^GREEN%^Ivy "+
         "%^RESET%^%^GREEN%^climbs the walls in some spots, while "+
         "%^BOLD%^%^WHITE%^silver lanterns %^RESET%^%^GREEN%^hang at "+
         "evenly spaced intervals in others. The provide a comfortable "+
         "light to the area that is neither too bright nor too dim.%^RESET%^",
      "chairs" : "%^RESET%^%^GREEN%^Made from %^WHITE%^wicker%^GREEN%^, "+
         "the most of the chairs are arranged in small clusters "+
         "although a few are set apart for the loners.%^RESET%^",
      "decor" : "%^RESET%^%^GREEN%^Potted %^BOLD%^trees %^RESET%^"+
         "%^GREEN%^and %^BOLD%^flowers %^RESET%^%^GREEN%^are tucked "+
         "into small alcoves and corners, while curious, perfectly "+
         "%^BOLD%^%^BLACK%^rounded stones %^RESET%^%^GREEN%^of varying "+
         "sizes are arranged here and there.%^RESET%^",
      "rug" : "%^RESET%^%^GREEN%^Made from a tough material meant to "+
         "weather storms, this is a simple %^ORANGE%^brown rug %^GREEN%^"+
         "that features the image of %^YELLOW%^t%^WHITE%^h%^RESET%^"+
         "%^ORANGE%^r%^BOLD%^%^WHITE%^e%^ORANGE%^e in%^WHITE%^t"+
         "%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^r%^ORANGE%^loc%^WHITE%^"+
         "k%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^n%^ORANGE%^g ri"+
         "%^WHITE%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^WHITE%^s%^RESET%^"+
         "%^GREEN%^.%^WHITE%^",
   ]));
   set_exits(([
      "south" : ROOMS"shadway4" ,
      "up" : ROOMS"3coinsbalcony"
   ]));
}  
