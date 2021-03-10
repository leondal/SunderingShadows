//estreet17 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"Here, %^MAGENTA%^Lila Way %^RESET%^joins "+
      "%^BOLD%^%^CYAN%^Viento Lane%^RESET%^, the divided thoroughfare "+
      "that runs westward between a %^BOLD%^stone building %^RESET%^to "+
      "the north and a lively %^ORANGE%^bar %^RESET%^on the south side "+
      "of the street.\n");
   set_exits(([
      "north" : ROOMS"estreet16",
      "south" : ROOMS"estreet18",
      "west" : ROOMS"viento58"
   ]));
   add_item("building","The building to the northwest has thick stone walls "+
      "and a %^GREEN%^green tiled roof%^RESET%^.  Near the top of "
      "the walls are long, narrow windows left glassless to help provide "+
      "ventilation.  Two large, paned windows hold suits of armor on display.");
   add_item("bar","Like many bars, the one to the southwest seems aged and "+
      "well-worn.  It is painted vaguely %^BOLD%^white %^RESET%^though "+
      "the sand and salt have blasted some of it away, revealing the "+
      "%^ORANGE%^wood %^RESET%^underneath.  It is trimmed in %^BOLD%^"+
      "%^BLUE%^blue%^RESET%^.");
}