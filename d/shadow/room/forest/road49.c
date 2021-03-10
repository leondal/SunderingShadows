#include <std.h>
#include "forest.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(SAVANNAH);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",0);
   set_short("Path through Grassy Plains");
   set_long(
   "%^BOLD%^You are walking on a path through grassy plains.%^RESET%^\n"+
   "The road stretches out to the north and southeast here, running"+
   " through the center of some grassy plains. The road leads out of the"+
   " plains to the southeast."
   );
   set_smell("default","You smell the fresh air and grass.");
   set_listen("default","You can hear animals in the grass.");
   set_items(([
   "road" : "This is really just a glorified dirt path, but someone keeps"+
   " it in good shape.",
   ({"plains","grassy plains"}) : "The grassy plains stretch out on either"+
   " side of you. The grass is not the lush green, but more of a dried"+
   " out yellowish-green shade. It is very tall, reaching over four"+
   " feet in some places. You get the impression that it's not the safest"+
   " of areas.",
   ]));
   set_exits(([
   "north" : FORESTDIR+"road48",
   "southeast" : FORESTDIR+"road50",
   "west" : MEADOWS+"plains9",
   "east" : MEADOWS+"plains16",
   ]));
}
void reset(){
   ::reset();
    if(!present("sign"))
      new("/d/common/obj/areas/meadow_sign.c")->move(TO);
}
