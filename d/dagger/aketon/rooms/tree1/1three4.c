#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Library upon the tree");
   set_long("%^GREEN%^Library upon the tree%^RESET%^
This room is filled with many racks of books. Most of the books here you "
      "notice are about spells, all different kinds of spells. A little "
      "stool is over there at the foot of one of the racks. Some magical "
      "bright balls light up the whole room. You can walk across the "
      "whole room from inbetween the racks to the otherside. An archway "
      "is over the east exit as well as another one at the south.");
   set_items( (["room":"The room is quite large, filled fully with books.",
      "racks":"Many wooden racks, each packed with books.",
      "books":"Most of the books are about magics and spells.",
      "stool":"You can use it to reach the books at the upper part of the "
      "racks.",
      "balls":"These magical balls give out a bright blue light.",
      "archway":"The archways lead east and south."]) );
   set_smell("default","Different odors of books fill the room.");
   set_listen("default","You can hear a fly buzzing around.");
   set_exits( (["east":RPATH1+"1three5",
      "south":RPATH1+"1three9"]) );
}
