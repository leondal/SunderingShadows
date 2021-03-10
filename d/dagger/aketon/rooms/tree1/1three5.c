#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Library upon the tree");
   set_long("%^GREEN%^Library upon the tree%^RESET%^
This room is also filled with many racks of books. Most of the books here "
      "you notice are about weapons, equipments and other items. Some "
      "stools are over there at the foot of the racks. Several magical "
      "bright balls light up the whole room. You can walk across the "
      "whole room from inbetween the racks to the otherside. An archway "
      "is over the west exit as well as another one at the south.");
   set_items( (["room":"The room is quite large, filled fully with books.",
      "racks":"Many wooden racks, each packed with books.",
      "books":"The books here are about weapons, equipments and other "
      "magical items.",
      "stools":"They can be used to reach the books at the upper part of "
      "the racks.",
      "balls":"These magical balls give out a bright blue light.",
      "archway":"The archways lead west and south."]) );
   set_smell("default","Different odors of books fill the room.");
   set_listen("default","It is all quiet here.");
   set_exits( (["south":RPATH1+"1three10",
      "west":RPATH1+"1three4"]) );
}
