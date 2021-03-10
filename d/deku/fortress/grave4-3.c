#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
  ::create();
   set_exits(([
//    "temple":"/d/magic/temples/kelemvor",
    "south" : GY_ROOMS+"grave3-3",
    "west":GY_ROOMS +"grave4-4",
    "east":GY_ROOMS +"grave4-2",
    "north" : GY_ROOMS +"grave5-3"
   ] ));
}

/*void reset() {
  object ob, ob1;
  int i;
  ::reset();
  if((string)EVENTS_D->query_time_of_day() == "night") { 
    if(objectp(environment(find_object_or_load(GY_MOBS+"k_priest_l")))) {
      return;
    }
    ob = find_object_or_load(GY_MOBS+"k_priest_l");
    ob->move(TO);
      for(i = 0;i < random(2) + 2;i++) {
        ob1 = new(GY_MOBS+"k_priest");
        ob1->move(TO);
        ob->add_follower(ob1);
      }
  }
}*/