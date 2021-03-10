#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CITY_ROOM + "ruin_base.c";

void create() {
  ::create();
  add_item( ({"hut", "intact hut"}), 
    "This hut is probably how all the others looked before"
   +" they fell to ruin. It is circular, a few metres in"
   +" diameter, built of stone with a%^ORANGE%^ wooden frame"
   +" that is all that remains of its roof. The walls slope"
   +" outward at the base, before narrowing toward the top."
   +" Entry is through an open doorway in the front.");
}

string long_desc(){
  return ::long_desc() + " However, one of the %^RESET%^huts"
  +" %^GREEN%^tucked away in the f%^BOLD%^%^GREEN%^o"
  +"%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^"
  +"a%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^e appears to be"
  +" relatively intact.";
}

