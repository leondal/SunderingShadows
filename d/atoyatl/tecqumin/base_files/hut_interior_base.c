#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit CITY_ROOM + "ruin_base.c";

void create() {
  ::create();
  add_item( ({"plant", "plants", "jungle plants"}), 
    "They are the same variety of plants to be found outside. These ones have just found their way inside.");
}

string long_desc(){
  return "The inside of this small hut is dark and %^ORANGE%^dusty%^RESET%^."
   +" %^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e"
   +" %^BOLD%^pl%^RESET%^%^GREEN%^a%^BOLD%^nts%^RESET%^ have grown through the"
   +" doorway, and %^GREEN%^creepers%^RESET%^ have found their way through "
   +"%^ORANGE%^cracks%^RESET%^ in the walls. It would have made a small and"
   +" cramped living space, with a bare %^ORANGE%^earth %^RESET%^floor and"
   +" nowhere to store much in the way of posessions. Still, it offers some"
   +" small relief from the humid heat outside.";
}

