#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_MAZE;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
//  set_short("%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
//           +" %^GREEN%^jungle");
  set_long( (:TO, "long_desc":) );
  set_items(([  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance");
}
void init() {
   ::init();
}

string long_desc(){
  ::long_desc();
return "%^GREEN%^A %^ORANGE%^huge tree%^GREEN%^ has fallen here,"
      +" %^RESET%^opening %^GREEN%^the jungle canopy to the %^CYAN%^sky"
      +" %^GREEN%^above. new growth is sprouting on and around the"
      +" enormous fallen trunk and various %^RESET%^bugs%^GREEN%^,"
      +" %^ORANGE%^mites%^GREEN%^ and %^BOLD%^%^BLACK%^termites%^RESET%^"
      +" %^GREEN%^have started eating into the %^ORANGE%^wood%^GREEN%^."
      +" Growths of %^BOLD%^%^WHITE%^fungus%^RESET%^%^GREEN%^,"
      +" %^ORANGE%^l%^GREEN%^i%^ORANGE%^ch%^RESET%^e%^ORANGE%^n"
      +" %^GREEN%^and%^BOLD%^ %^GREEN%^moss%^RESET%^%^GREEN%^ work to aid"
      +" the process of %^BOLD%^%^BLACK%^decomposition%^RESET%^%^GREEN%^,"
      +" returning the nutrients of the %^ORANGE%^wood%^GREEN%^ to the"
      +" soil.\n";
}

