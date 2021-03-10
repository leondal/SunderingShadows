#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit TECBASE + "jung_base.c";


void create() {
  ::create();

  add_item( ({"causeway", "stone causeway", "broad stone causeway"}), 
    "The ancient road has been largely overgrown by the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" Only patches of stone remain, green with %^GREEN%^moss%^RESET%^ and"
   +" crossed over with %^ORANGE%^tree roots%^RESET%^. Even so, what is left"
   +" suggests that long ago this may have been a major causeway.");

  set_exits(([
      "north" : CITY_ROOM + "clear_road02"
   ]));
}

string long_desc(){
  return ::base_desc() + "To the north, the" 
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" opens out onto a broad stone causeway running east to west.";
}
