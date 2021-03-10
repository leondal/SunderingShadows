#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_INT_BASE;

int mahogany, sandalwood;
string long_desc();

void create() {
  ::create();
  set_short("A small chamber");
  set_items(([ ({"chest", "chests"}): "One of the chests appears to be"
                                  +" made"
                                  +" from mahogany and bound with copper"
                                  +" strips. The other is made of lighter"
                                  +" sandalwood and bound with iron. They"
                                  +" are both large, measuring some five"
                                  +" feet across by three feet deep, and"
                                  +" standing about four feet high, with"
                                  +" domed tops",
            "sandalwood chest": "The sandalwood chest bears the image of"
                               +" a forked tongued jaguar on the front",
            "mahogany chest": "The mahogany chest bears the image of a"
                             +" squat, ugly toad like creature on the"
                             +" front" ]) );
  set_exits( ([ "west" : ROOMS + "guardcham"]) );
  set_search("chest", (:TO, "chest_search":) );
  set_search("mahogany chest", (:TO, "mahogany_search":) );
  set_search("sandalwood chest", (:TO, "sandalwood_search":) );
  set_door("door",ROOMS+"guardcham","west",0); 
  set_door_description("door","An ancient stone door, balanced"
                                  +" somehow on invisible hinges");
  mahogany = 0;
  sandalwood = 0;
}


string long_desc(){
    return "This small chamber contains two large chests. The only"
          +" visible exit is through a door to the west, leading back to"
          +" the main entrance chamber";
}

void chest_search()
{
  tell_object(TP, "Do you wish to search the mahogany chest or the sandalwood one?");
  return;
}

void mahogany_search(){
  object knife;
  if (mahogany)
  {
    tell_object(TP, "That chest appears to have been searched already");
    tell_room(TO, TPQCN + " rifles around in the %^BOLD%^%^BLACK%^mahogany chest%^RESET%^, but doesn't seem to find anything", TP);
    return;
  }
  tell_object(TP, "The chest is full of ceremonial paraphernalia."
    +" %^BOLD%^%^YELLOW%^Brass mirrors%^RESET%^, %^BOLD%^%^WHITE%^thick"
    +" candles%^RESET%^, stone figures and the like. In amongst it all,"
    +" you find a %^BOLD%^%^BLACK%^jet black dagger", ); 
  tell_room(TO, TPQCN + " seems to find something in the %^BOLD%^%^BLACK%^mahogany chest%^RESET%^.", TP);
  knife = new (OBJ + "sac_knife");
  knife->move(TO);
  mahogany = 1;
}

void sandalwood_search(){
  object belt;
  if (sandalwood)
  {
    tell_object(TP, "That chest appears to have been searched already");
    tell_room(TO, TPQCN + " rifles around in the %^ORANGE%^sandalwood%^RESET%^ chest, but doesn't seem to find anything", TP);
    return;
  }
  tell_object(TP, "The chest is full of ceremonial clothing, in generally poor states of repair. In amongst it all,"
    +" you find a %^ORANGE%^thick leather belt%^RESET%^ of particularly sturdy construction.", ); 
  tell_room(TO, TPQCN + " seems to find something in the %^BOLD%^%^BLACK%^mahogany chest%^RESET%^.", TP);
  belt = new (OBJ + "game_belt");
  belt->move(TO);
  sandalwood = 1;
}
