#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit R_ROAD_BASE;


void create() {
  ::create();
  add_item( ({ "plaza", "grand plaza"}), "The plaza forms a large clearing in the"
    +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e"
    + "%^RESET%^, and the %^BOLD%^%^CYAN%^s%^WHITE%^k%^CYAN%^y%^RESET%^ is visible"
    +" above it."  );
  set_exits(([ 
      "west" : CITY_ROOM + "ragged_road03",
      "east" : CITY_ROOM + "city_jung17"
   ]));
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){

return base_desc() + "Here and there, the jungle floor opens up revealing"
  +" patches of worked %^RESET%^gray stone%^GREEN%^, apparently the remains"
  +" of an %^RESET%^ancient road %^GREEN%^heading east to west. The road leads"
 +" to the %^RESET%^grand plaza%^GREEN%^ to the west. To the east, it fades back into"
 +" the j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ngle.";

}
