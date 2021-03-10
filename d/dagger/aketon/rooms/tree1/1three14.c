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
      "very clean and no sign of much use. The corridor continues north "
      "and east. Two archways leading into some large rooms at west and "
      "south.");
   set_items( (["trunk":"Size of the huge trunk is beyond imagination.",
       "corridor":"It continues north and east.",
       "archways":"The archways lead west and south.",
       "floor":"It is not rottened not well traveled."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city coming from beneath "
      "you.");
   set_exits( (["north":RPATH1+"1three11",
      "east":RPATH1+"1three15",
      "south":RPATH1+"1three19",
      "west":RPATH1+"1three13"]) );
}
