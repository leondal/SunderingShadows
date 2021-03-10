#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TECBASE + "jung_base.c";

void create() {
  ::create();
  add_item( ({"path", "small path"}), 
    "The north-south %^ORANGE%^path%^RESET%^ you can see to the west is very"
    +" %^ORANGE%^o%^GREEN%^v%^ORANGE%^e%^GREEN%^rg%^ORANGE%^ro%^GREEN%^w"
    +"%^ORANGE%^n%^RESET%^, but a few stones are still visible on the ground.");

  add_item( ({"hut", "huts", "stone hut", "stone hunts", "ruin", "ruins"}), 
    "The ruins are mostly obscured by the"
   +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" f%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^a"
   +"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^e%^RESET%^, but you can see that there"
   +" are a number of them to your west. You will have to get closer to get a"
   +" better look.");

  add_item( ({"break", "break in the jungle", "break in the jungle foliage"}), 
    "Beyond the ruins of the %^ORANGE%^path%^RESET%^ and scattered huts to the"
    +" west, the" 
    +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
    +" f%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^a"
    +"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^e%^RESET%^ seems to break in a line"
    +" running north to south. You can't make out why from here.");

  set_exits(([
      "west" : CITY_ROOM + "ruin02"
   ]));
}

string long_desc(){
  return ::base_desc() + " To the west, you can make out the ruins of a%^ORANGE%^"
    +" small path%^RESET%^ running north to south, and a number of stone huts."
    +" There also appears to be a break in the"
    +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
   +" f%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^a"
   +"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^e%^RESET%^ in the same direction.";
}
