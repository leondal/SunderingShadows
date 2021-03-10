#include <std.h>

inherit ROOM;
#include "../areadefs.h"

void create() {
    ::create();
    set_terrain(HUT);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("outdoors",1);
    set_short("Sandy beach on the Isle of Attaya.");
    set_long("
You walk to the edge of the beach to where it meets the jungle and you notice some
interesting things. First of all against a large palm tree lays the fresh
corpse of what appears a well-equipped adventurer. His blood stains the 
the sand around him. Not far away from him stands a man cleaning his
daggers. The cliff blocking you off from the beach to the north of you
is bigger now, and the only way out from here is the way you came.
The noise from the wind and the waves makes this part of the beach
very remote indeed.
");

     set_listen("default","The wind gusts loudly here and "+
                "and the waves crash loudly.");
 
    set_exits(([

       "east" : ROOMS+"senbeach3",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet "+
         "tall, are bending in the powerful winds that rip over the "+
         "island.",
         "beach" : "The beach here is rippled from the effects of a "+
         "recent tide.  The sand is very finely granulated.",
         "corpse" : "The bloody corpse of some unlucky adventurer lays "+
         "against one of the large palm trees. He has multible stab "+
         "wounds covering his body."
    ] ));
}

void reset()
{
  ::reset();
  if(!present("assassin"))
  new(MON+"assassin2.c")->move(TO);
}
