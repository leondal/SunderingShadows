#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_climate("tropical");
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
  set_short( (: TO, "short_desc" :) );
  set_long( (:TO, "long_desc":) );
  set_items(([  ({"jungle", "encroaching jungle"}) : "From the mighty"
  +" %^ORANGE%^ boles %^RESET%^and reaching %^GREEN%^canopies%^RESET%^"
  +" of%^GREEN%^ ancient trees%^RESET%^ to the twisted tangles of vines"
  +" and impeding undergrowth, the"
  +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
  +" %^RESET%^bordering the plaza and other buildings is lush, green and"
  +" teeming with life." ,
                ({"stone", "stones"}) : "The slabs of gray stone the plaza"
  +" is built of were once carefully laid and flat, but have been shifted"
  +" and jumbled as if shaken by some great force, so that the ground is"
  +" now quite uneven.",
({"ziggurat", "massive ziggurat", "pyramid", "stone pyramid", 
                                          "stepped stone ziggurat"}) : 
   "The massive ziggurat located to the south of the plaza takes the form"
  +" of a stepped stone pyramid, with four sides. Each of the sides you"
  +" can see has a broad central stairway, leading up to what looks like"
  +" a covered ceremonial altar at the top.",
   ({"structure", "palatial structure", "palace", "jaguar"}): "The palatial"
  +" structure to the north has been built in the form of the head and"
  +" forequarters of a great jungle cat. The entrance appears to be"
  +" through the open snarling mouth, and the forelegs lead to low guard"
  +" towers on either side. Atop the beast's head there is a balcony which"
  +" overlooks the plaza."  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
  set_exits( (["west" : CITY_ROOM + "clear_road01",
               "east" : CITY_ROOM + "clear_road02",
              "north" : CITY_ROOM + "palace_approach",
              "south" : CITY_ROOM + "zig_approach" ]) );
}


string short_desc(){
  return "A grand stone plaza in the %^GREEN%^j%^BOLD%^%^GREEN%^u"
       + "%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e";
}

string long_desc(){

return "This large, square stone plaza, grand reminder of a long lost"
  +" %^CYAN%^civilisation%^RESET%^, stands in the middle of an"
  +" %^GREEN%^anc%^ORANGE%^i%^GREEN%^ent"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e%^RESET%^"
  +" whose trees and other plants crowd in around the edges. The plaza" 
  +" itself seems to have weathered the years and fought off the encroaching"
  +" greenery, when many lesser structures have been swallowed up. It"
  +" is built of the same gray stone as the rest of the city's"
  +" structures, cut in huge slabs and laid flat to form a level floor."
  +" Traces of %^BOLD%^%^CYAN%^azure%^RESET%^ and %^ORANGE%^ochre"
  +" %^RESET%^pigment remain, suggesting that the paving was once highly"
  +" decorated, though no recognisable designs remain. Also relatively"
  +" unscathed are the massive ziggurat to the south, and a palatial"
  +" structure in the form of a %^BOLD%^%^BLACK%^jaguar%^RESET%^ which"
  +" lies to the north. A broad %^ORANGE%^stone causeway%^RESET%^ leads"
  +" into what remains of the city's grand residential districts to the"
  +" east and west.";
}
