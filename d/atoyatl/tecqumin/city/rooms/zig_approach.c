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
   "The massive ziggurat is right in front of you. It takes the form"
  +" of a stepped stone pyramid, with four sides. Each of the sides you"
  +" can see has a broad central stairway, leading up to"
  +" a covered ceremonial altar at the top.",
   ({"structure", "palatial structure", "palace", "jaguar"}): "The palatial"
  +" structure to the north has been built in the form of the head and"
  +" forequarters of a great jungle cat. The entrance appears to be"
  +" through the open snarling mouth, and the forelegs lead to low guard"
  +" towers on either side."  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasiownally heard"
                     +" further in the distance.\n");
  set_exits( ([
              "north" : CITY_ROOM + "plaza",
              "south" : ROOMS + "step7" ]) );
}


string short_desc(){
  return "Before a mighty stone ziggurat";
}

string long_desc(){

return "You are at the south end of a large, square stone plaza in the middle of an"
  +" %^GREEN%^anc%^ORANGE%^i%^GREEN%^ent"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e%^RESET%^"
  +" whose trees and other plants crowd in around the edges. Directly before you to"
  +" the south, the plaza leads to an enormous stone ziggurat which takes the form"
  +" of a stepped pyramid with a central stairway leading up to a ceremonial altar at"
  +" the top. Also relatively unscathed is a palatial structure in the form of a"
  +" %^BOLD%^%^BLACK%^jaguar%^RESET%^ which lies to the north of the plaza. Just north"
  +" of you, A broad %^ORANGE%^stone causeway%^RESET%^ leads"
  +" into what remains of the city's grand residential districts to the"
  +" east and west.";
}
