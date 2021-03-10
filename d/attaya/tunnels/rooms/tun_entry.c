//stefano_entry.c - The entry point for Stefano's house from the outside world
#include <std.h>
#include <move.h>
//#include "/d/player_houses/stefano/stefano.h"
#include "../tunnel.h"

inherit VAULT;

string long_desc();

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("The end of a stream");
  set_short("The end of a %^BOLD%^%^BLUE%^s%^CYAN%^tr%^RESET%^%^CYAN%^e"
           +"%^BOLD%^%^BLUE%^am%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([
  (({"stream","flowing stream"})) : "The gently bubbling stream speeds up"
      +" as it approaches the hole and then suddenly disappears",
  ({"jungle","jungles","trees"}) : "The jungle is filled with palm trees"
      +" and other tropical plants.  There's a foreboding sort of feel to"
      +" it.",
  "hole" : "The %^BOLD%^%^BLACK%^hole%^RESET%^ looks dark and forbidding."
          +" With the water disappearing into it so rapidly it would be"
          +" almost suicidal to jump in there."
  ]));
  set_smell("default","You smell fresh water.");
  set_listen("default","You hear the gentle sound of the stream.");
  set_exits(([
      "west" : TUNNELS+"stefano_entry",
  ]));

}
void init() {
   ::init();
   add_action("enter_hole","jump");
   add_action("enter_hole","dive");
   add_action("enter_hole","enter");
}

string long_desc(){
return "%^GREEN%^You are standing on the sandy banks of a flowing%^BOLD%^"
     +" %^BLUE%^s%^CYAN%^tr%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^am%^RESET%^"
     +"%^GREEN%^.  The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
     +"%^GREEN%^ngle%^RESET%^%^GREEN%^ presses in all around you,"
     +" blocking travel in every way except back to the west."
     +"  Surprisingly, the %^CYAN%^stream %^GREEN%^does not seem to"
     +" continue further to the east, but disappears into a %^BOLD%^"
     +"%^BLACK%^hole %^RESET%^%^GREEN%^in the ground underneath a"
     +" %^RESET%^large rock%^GREEN%^, %^CYAN%^g%^RESET%^u%^CYAN%^rgl"
     +"%^RESET%^i%^CYAN%^ng %^GREEN%^and %^CYAN%^fr%^RESET%^o%^CYAN%^th"
     +"%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^ng %^GREEN%^as it goes.\n";
}


int enter_hole(string str) {
   if(!str) {
     tell_object(TP, query_verb()+" where?");
     return 1;
   }
   if(str == "hole" || str == "in" || str == "into hole"
                    || str == "in hole"|| str == "in there") {
      tell_object(TP,"Taking a deep breath, you "+ query_verb()+ " into"
                    +" the hole!");
      tell_room(ETP,TPQCN+" takes a deep breath and " + query_verb()
                    + " into the hole!",TP);
      TP->move(TUNNELS+"tumble");
      find_object_or_load(TUNNELS+"tumble")->fall(TP);
      return 1;
   }
   else return 0;
}
