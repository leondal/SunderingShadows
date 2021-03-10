#include <std.h>
#include "../dragon.h";

inherit "/std/vault";

void create() {
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_short("Sanctuary Sewers");
   set_long(
      "%^BOLD%^%^BLACK%^This is a large oval chamber somewhere within the sewers under the"+
      " city of Sanctuary. Faintly luminescent lichen clings to the walls,"+
      " reflecting lightly off the water that occasionally drips from the"+
      " high ceiling. Towards the east beside the"+
      " stone wall sits a circle of stones."
   );
   set_exits(([
      "portal" : SEWER+"sewer49"
   ] ));
   set_items(([
      (({"stones","circle","circle of stones"})):"There are about 12 rough cut stones layed out to form a circle. These strange stones are reminiscent of a summoning circle. You wonder what might happen if you were to stand in the circle.",
      "sewers":"The disgusting tunnels of waste under Sanctuary."
   ] ));
   set_property("no teleport", 1);
   set_smell("default","The rotting smell of waste is very strong in these tunnels.");
   set_listen("default","There is only silence here.");
   set_terrain(SHALLOW_WATER);
   set_travel(SLICK_FLOOR);
}

void init() {
  ::init();
  add_action("stand", "stand");
}

int stand(string str) {
   if(!str) {
   tell_object(this_player(), "Stand in what?");
   return 1;
   }
   if(str != "in circle") {
   tell_object(this_player(), "Stand in what?");
      return 1;
   }
   if(present("toris")){
      tell_object(TP,"%^BOLD%^%^RED%^Toris guards over the circle.");
      return 1;
   }
   tell_object(TP,"%^GREEN%^Green smoke arises from the circle and begins to wrap you in a cloak of fog.");
   tell_room(ETP, "%^GREEN%^Some green smoke rises from the stone as "+TP->query_cap_name()+" begins to fade out of existance.",TP);
   call_out("go_stone", 10);
   return 1;
}

void go_stone() {
  tell_object(TP,"%^RED%^You notice that your existance has been moved to somewhere else completely different.");
  TP ->move_player(TOWER+"bottom01.c");
}

void reset() {
  if(!present("toris")) {
    new(MON+"toris")->move(TO);
  }
}
