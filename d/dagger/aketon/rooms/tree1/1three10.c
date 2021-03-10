#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Library upon the tree");
   set_long("%^GREEN%^Library upon the tree%^RESET%^
This room is filled with many racks of books. Most of the books here you "
      "notice are about literatures. Elven, Gnomish, Ogrish, all racial "
      "literatures can be found here. Some small stools are over there at "
      "the foot of the racks. Several magical bright balls light up the "
      "whole room. You can access the other side of the room pass the "
      "paths inbetween the racks. An archway is over the west leading out "
      "the library, another one opens into another room.");
   set_items( (["room":"The room is quite large, filled fully with books.",
      "racks":"Many wooden racks, each packed with books.",
      ({"books","literatures"}):"The books here are all about literatures "
      "of different races, Gnomish, Elven ...",
      "stools":"These stools can be used to reach the books at the upper "
      "part of the racks.",
      "balls":"These magical balls give out a bright blue light.",
      "archway":"The archways lead west and north."]) );
   set_smell("default","Different odors of books fill the room.");
   set_listen("default","You hear some foodsteps coming from outside "
      "the library.");
   set_exits( (["north":RPATH1+"1three5",
      "west":RPATH1+"1three9"]) );
}
