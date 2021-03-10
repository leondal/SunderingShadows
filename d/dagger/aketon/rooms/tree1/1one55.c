#include "/d/dagger/aketon/short.h"

inherit HOTEL;

void create() {
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_short("Aketon Whitedoll Hotel");
   set_long("%^BOLD%^Aketon Whitedoll Hotel%^RESET%^
There is a registry counter on the south side of the room. The clerk will "
      "check you in and out. All of the rooms here are very secure. We "
      "have never had a death or theft, of any players or possessions "
      "since we opened. This hotel has beds for rent. <help hotel> will "
      "get you help on renting a room in the hotel.");
   set_listen("default","You hear the shuffling of strangers moving "
      "around the hotel.");
   set_smell("default","You hear the sounds of people moving about around "
      "you.");
   set_search("default","You look around aimlessly, and find nothing "
      "worthwhile.");
   set_exits( (["north":RPATH1+"1one46"]) );
   set_rooms( (["singleroom":1,
      "doubleroom":2,
      "tripleroom":3,
      "quadroom":4,
      "westgroup":5,
      "eastgroup":5]) );
    set_cost(15);
}
