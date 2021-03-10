#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Corridor upon the tree");
   set_long("%^GREEN%^Corridor upon the tree%^RESET%^
This is a wide corridor built around the huge tree trunk. It is much "
      "quieter than the lower levels of the city. The wooden floor seems "
      "very clean and no sign of much use. The corridor continues south "
      "and west. Two archways leading into some large rooms at east and "
      "north.");
   set_items( (["trunk":"Size of the huge trunk is beyond imagination.",
       "corridor":"It continues south and west.",
       "archways":"The archways lead east and north.",
       "floor":"It is not rottened not well traveled."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city coming from beneath "
      "you.");
   set_exits( (["north":RPATH1+"1three4",
      "east":RPATH1+"1three10",
      "south":RPATH1+"1three12",
      "west":RPATH1+"1three8"]) );
}
