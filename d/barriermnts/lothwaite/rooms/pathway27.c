//pathway27.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEND;

void create(){
   ::create();
   set_long( ::query_long()+"  This short pathway leads south back to the main "+
      "path, or north to a large home.  The front of the home is fitted with grand "+
      "columns and carved wood.\n");
   add_item("home","Much larger than the other homes in the village, this one "+
      "must belong to someone of great import.  Columns march along the front of "+
      "the house, while the wood of the house itself has been carved in great detail.");
   add_item("columns","Fluted columns stand at intervals along the front of "+
      "the house, adding a touch of grandeur.");
   add_item("carvings","The carvings are of intricate, detailed knots gilded and "+
      "polished to a high shine.  Within the knots flit the images of countless "+
      "bees made of %^YELLOW%^amber %^RESET%^and %^BOLD%^%^BLACK%^onyx%^RESET%^.");
   add_item("carved wood","The carvings are of intricate, detailed knots gilded and "+
      "polished to a high shine.  Within the knots flit the images of countless "+
      "bees made of %^YELLOW%^amber %^RESET%^and %^BOLD%^%^BLACK%^onyx%^RESET%^.");
   set_exits(([
      "north" : PATHEXIT"leader1",
      "south" : PATHEXIT"pathway26",
   ]));
   set_door("door",PATHEXIT"leader1","north",0);
   set_door_description("door","This door is made of solid pine planks bound "+
      "seamlessly together.  The highly varnished door has been carved with "+
      "knotwork and images of bees fitted with %^YELLOW%^amber %^RESET%^and "+
      "%^BOLD%^%^BLACK%^onyx%^RESET%^.");
}