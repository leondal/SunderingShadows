#include <std.h>
#include <move.h>
#include "../../tecqumin.h"
 
inherit CROOM;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A ruined apothecary");
  set_short( "%^CYAN%^A %^ORANGE%^ruined %^CYAN%^apothecary" );
  set_long( "This large circular building has a square stone doorway"
    +" with a stone lintel, but no door. The walls slope outwards at the"
    +" base, before converging as they rise up toward the roof. Post"
    +" holes in the walls suggest it once had a ceiling and probably a"
    +" second floor above, but all of this is long gone. By the"
    +" standards of the %^CYAN%^Tecqumin%^RESET%^ buildings, this would"
    +" have been a rather grand home, but the contents have long"
    +" disappeared or %^ORANGE%^r%^BOLD%^%^BLACK%^o%^RESET%^"
    +"%^ORANGE%^tt%^GREEN%^e%^ORANGE%^d%^RESET%^ away, and the"
    +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng"
    +"%^RESET%^%^GREEN%^l%^BOLD%^e %^RESET%^has begun to find its way"
    +" inside." );
  set_items(([  ({"jungle", "plants", "jungle plants"}) : "The%^BOLD%^"
    +"%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^"
    +"l%^BOLD%^e %^RESET%^%^GREEN%^plants%^RESET%^ have found their way"
    +" into the inside of the building. The floor is covered with"
    +" %^GREEN%^greenery%^RESET%^, and %^GREEN%^creepers%^RESET%^"
    +" and tree branches intrude through the door and windows" ,
     ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
  set_exits((["out" : CITY_ROOM + "grand_hut01"]));
}
