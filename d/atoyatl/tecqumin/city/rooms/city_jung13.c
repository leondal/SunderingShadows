#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TECBASE + "jung_base.c";

void create() {
  ::create();

  add_item( ({"ruin", "ruined building", "stone building", 
          "large stone building", "ruin of a large stone building"}),
    "To the east is the partially collapsed ruin of a circular"
    +" building. Not much is left standing, but the quantity of"
    +" stone suggests a much grander building than the stone huts"
    +" to be found further west in the jungle.");

  add_item( ({"palace", "", "palatial structure"}), 
    "You can't see much from here, but the building is made of stone, and is"
   +" impressively large in scale.");

  set_exits(([
      "east" : CITY_ROOM + "grand_ruin03",
 "northwest" : JUNG_ROOM4 + "city_jung14"
   ]));
}

string long_desc(){
  return ::base_desc() + "To the east, you can make out the ruin of a"
    +" %^RESET%^large stone building%^GREEN%^. To the west, the top of"
    +" a %^RESET%^palatial structure %^GREEN%^can be made out above the"
    +" treetops.";
}
