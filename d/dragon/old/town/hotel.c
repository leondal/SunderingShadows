#include <std.h>
#include "/d/shadow/mon/melnmarn.h"
inherit HOTEL;
void create(){
    ::create();
    set_property( "light" , 3);
    set_property("indoors" , 1);
    set_short("Hotel Sanctuary");
    set_long("%^BOLD%^%^BLUE%^
The village inn is a rain-drenched single story structure with few windows,
adjoining stables and a large weather-worn crest painted on the front wall.
The crest depicts a green dragon, its wings unfolded, clutching an ale
tankard with two fearsome claws.  This hotel has rooms for rent. 
%^YELLOW%^< help hotel >%^BLUE%^ will get you help on renting a room.\n");
    set_listen("default","You hear the shuffling of strangers moving around
the hotel.");
   set_listen("default","You hear the snoring of wondering adventurers.");
    set_search("default","You look around aimlessly, and find nothing
worthwhile.");
    set_exits( ([
        "south":"/d/dragon/town/roadW1"
             ]) );
    set_rooms(([
        "westgroup":6,
        "eastgroup":5,
        "southroom":3,
        "singleroom":1,
        "doubleroom":2,
        "tripleroom":3,
        "quadroom":4,
        ]));
    set_cost(10);
} 

void reset() {
  ::reset();
  if(!present("pumpkin")) {
   new("/d/dragon/obj/misc/jack")->move(this_object());
  }
}
