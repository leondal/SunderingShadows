#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Corridor upon the tree");
   set_long("%^GREEN%^Corridor upon the tree%^RESET%^
This is a wide corridor built around the huge tree trunk. A large window "
      "occupies the whole north wall where you can see far off into the "
      "forest if it weren't for all the leaves blocking your sight. It is much "
      "quieter than the lower levels of the city. The wooden floor seems "
      "very clean and no sign of much use. The corridor continues east "
      "and west. Some paintings are hanging on the south wall.");
   set_items( (["trunk":"Size of the huge trunk is beyond imagination.",
        "leaves":"Umm... without these the tree will die sooner or longer.",
       "corridor":"It continues east and west.",
       "paintings":"Paintings of the forest area.",
       "window":"The single large window occupied the whole north wall.",
       "floor":"It is not rottened not well traveled."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city coming from beneath "
      "you.");
   set_exits( (["east":RPATH1+"1three9",
      "west":RPATH1+"1three7"]) );
}
