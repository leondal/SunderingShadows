#include <std.h>
#include "../dragon.h";

inherit BTOWER;

void create() {
   ::create();
   set_long(
      "%^RESET%^There is only one thing that stands out in this"+
      " room. It would be completely bare if it were not for the"+
      " %^RESET%^%^GREEN%^circle of stones %^RESET%^laying in the middle of the floor."
   );
   set_items( ([
      ({"circle","circle of stones"}) : "This is a group of stones spaced exactly the same distance from each other in the pattern of a circle.",
   ]) );
   set_exits( ([
      "south" : TOWER+"hall01",
   ]) );
}


void init() {
  ::init();
  add_action("stand", "stand");
}

int stand(string str) {
   if(!str) {
   tell_object(this_player(), "You stand.");
   return 1;
   }
   if(str != "in circle") {
      tell_object(this_player(), "You stand "+str+".");
      return 1;
   }
   if(present("minotaur")){
      tell_object(TP,"%^BOLD%^%^RED%^The minotaur guards over the circle.");
      return 1;
   }
   tell_object(TP,"%^RESET%^%^GREEN%^Green smoke arises from the circle and begins to wrap you in a cloak of fog.");
   tell_room(ETP, "%^RESET%^%^GREEN%^Some green smoke rises from the stone as "+TP->query_cap_name()+" begins to fade out of existance.",TP);
   call_out("go_stone", 10);
   return 1;
}

void go_stone() {
  tell_object(TP,"%^RESET%^%^RED%^You notice that your existance has been moved to somewhere else completely different.");
  TP ->move_player(TOWER+"top");
}

void reset() {
  if(!present("minotaur")) {
    new(MON+"minotaur")->move(TO);
  }
}
