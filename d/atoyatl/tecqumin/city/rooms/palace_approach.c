#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit VAULT;

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(DECAYED_FLOOR);
  set_name( "In front of a building shaped like a jaguar" );
  set_short("In front of a building shaped like a %^ORANGE%^j"
    +"%^BOLD%^%^BLACK%^a%^ORANGE%^g%^BOLD%^u%^BOLD%^%^BLACK%^a"
    +"%^RESET%^%^ORANGE%^r%^RESET%^");
  set_long( "You stand at the approach to a most unusual stone building."
    +" Carved in the shape of the head and forequarters of a %^ORANGE%^j"
    +"%^BOLD%^%^BLACK%^a%^ORANGE%^g%^BOLD%^u%^BOLD%^%^BLACK%^a%^RESET%^"
    +"%^ORANGE%^r%^RESET%^. To enter, you would head north, into the mouth"
    +" of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
    +"%^GREEN%^l%^BOLD%^e %^YELLOW%^c%^BOLD%^%^BLACK%^a%^YELLOW%^t%^RESET%^."
    +" A grand city plaza lies to the south. " );
  set_items(([  ({"jungle", "encroaching jungle"}) : "From the mighty"
  +" %^ORANGE%^ boles %^RESET%^and reaching %^GREEN%^canopies%^RESET%^"
  +" of%^GREEN%^ ancient trees%^RESET%^ to the twisted tangles of vines"
  +" and impeding undergrowth, the"
  +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
  +" %^RESET%^bordering the plaza and other buildings is lush, green and"
  +" teeming with life." ,
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
  +" overlooks the plaza.",
 ({"balcony"}) : "The balcony sits right atop the section of the building"
  +" shaped into the head of the jaguar. It probably offers great views"
  +" of the plaza, and would be a grand spot from which to address"
  +" thronging crowds below."  ]));

  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
  set_exits((["south"  : CITY_ROOM + "plaza",
              "enter"  : CITY_ROOM + "palace_entrance"  ]));
  set_pre_exit_functions( ({"enter"}), ({"go_north"}) );
}

int go_north(){
  tell_object(TP, "%^CYAN%^You step forward, into the mouth of the%^ORANGE%^"
    +" j%^BOLD%^%^BLACK%^a%^ORANGE%^g%^BOLD%^u%^BOLD%^%^BLACK%^a%^RESET%^"
    +"%^ORANGE%^r%^RESET%^");
  return 1;
}

