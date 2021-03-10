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
  set_items(([({"water", "waterfall"}) : "The waterfall is hardly more than a trickle of"
                                        +" %^ORANGE%^muddy%^RESET%^ liquid running down a few rocks."
                                        +" But it is water, and it's definitely falling, hence the"
                                        +" name. You might want to think about whether you want to"
                                        +" drink it, though.",
                "rocks" : "The waterfall runs down a brief escarpment of loose shale." ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","You can hear the musical tinkling of the water as it runs down the rocks");
}
void init() {
   ::init();
   add_action("enter", "enter");
   add_action("drink", "drink");
}

string long_desc(){
  return ::long_desc()+ "%^BOLD%^%^GREEN%^There is a small %^BOLD%^%^BLUE%^w%^CYAN%^a%^BLUE%^terf%^RESET%^"
    +"%^CYAN%^a%^BOLD%^%^BLUE%^ll %^GREEN%^here, and a %^CYAN%^tiny stream %^GREEN%^leading away into the"
    +" jungle." ;
}

int drink(string str){
  if (str != "water"){
    return notify_fail("Do you want to drink the water? And are you sure about that?");
  }
  if(!TP->add_quenched(3000)) {
    notify_fail("You are too bloated to drink that!\n");
    return 0;
  }
  tell_object(TP, "You scoop %^BOLD%^%^BLUE%^water%^RESET%^ from the little stream and drink deeply. Fortunately,"
       +" it seems perfectly okay to drink. At least so far.");
  tell_room(TO, TPQCN + " scoops %^BOLD%^%^BLUE%^water%^RESET%^ from the little stream and drinks deeply.", TP);
  return 1;
}

int enter(string str){
  if (str !="waterfall"){
    return notify_fail("enter what?");
  }
  tell_object(TP, "You must be joking. Not %^BOLD%^%^BLUE%^every%^RESET%^ waterfall has a fancy cave"
                  +" hidden behind it, you know. This one's just a pile of rocks with some water"
                  +" trickling down it.");
  return 1;
}

