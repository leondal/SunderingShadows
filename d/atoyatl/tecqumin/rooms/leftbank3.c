#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
  set_short("%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle");
  set_long( (:TO, "long_desc":) );
  set_items(([  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","You can hear the water flowing swiftly by. In the"
                     +" background there is the constant hum of insect"
                     +" activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance");
}


string long_desc(){
return"%^GREEN%^You are on the left hand bank of a %^BLUE%^river. " 
      +"%^GREEN%^The jungle forms a dense %^BOLD%^%^BLACK%^tangle"
      +"%^RESET%^%^GREEN%^, barring passage in most directions. %^BOLD%^"
      +"%^GREEN%^Vibrant %^RESET%^%^GREEN%^gr%^BOLD%^%^GREEN%^ee%^RESET%^"
      +"%^GREEN%^n %^BOLD%^%^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^"
      +"%^GREEN%^nts%^RESET%^%^GREEN%^ with thick, waxy leaves gather"
      +" round the bases of %^BOLD%^%^BLACK%^ancient%^RESET%^%^GREEN%^"
      +" growth trees with thick boles and %^RESET%^%^ORANGE%^twisted"
      +" branches%^GREEN%^. %^BOLD%^%^WHITE%^F%^MAGENTA%^l%^BOLD%^"
      +"%^WHITE%^ow%^CYAN%^e%^BOLD%^%^WHITE%^rs%^RESET%^%^GREEN%^ with"
      +" %^BOLD%^%^MAGENTA%^v%^YELLOW%^i%^MAGENTA%^v%^CYAN%^i%^MAGENTA%^"
      +"d %^BLUE%^c%^RED%^o%^YELLOW%^l%^MAGENTA%^o%^CYAN%^u%^YELLOW%^r"
      +"%^BLUE%^s%^RESET%^%^GREEN%^ spring out from %^BOLD%^%^BLACK%^dark"
      +"%^RESET%^%^GREEN%^, surprising corners and thick, %^RESET%^"
      +"%^ORANGE%^trailing vines%^GREEN%^ wrap around the trees and other"
      +" plants. The plants grow quickly here, and such trails as there"
      +" are change as often as the lives and habits of the animals and"
      +" other creatures who inhabit this place.\n";
}

