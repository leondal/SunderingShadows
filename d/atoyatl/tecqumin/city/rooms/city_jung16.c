#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit TECBASE + "jung_base.c";


void create() {
  ::create();

  add_item( ({"palace", "", "palatial structure", "large building"}), 
    "You can't see much from here, but the building is made of stone, and is"
   +" impressively large in scale.");

  set_exits(([
      "northeast" : CITY_ROOM + "city_jung15"
   ]));
}

string long_desc(){
  return ::base_desc() + " Generally to the east, you can make out the top"
  +" of a %^RESET%^palatial structure%^GREEN%^, peeking out above the tops of"
  +" the trees";
}
