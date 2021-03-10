#include <std.h>
#include "forest.h"
inherit "/d/shadow/room/forest/road1";

void create()
{
   ::create();
   set_terrain(MEADOWLANDS);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",0);
   set_short("Path through the Meadow Lands");
   set_items(([
   "road" : "This is really just a glorified dirt path, but someone keeps"+
   " it in good shape.",
   ({"flowers","%^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^"}) : "Wildflowers dot the meadow lands to"+
   " the west.",
   "birds" : "There are many birds singing in the trees in the forest"+
   " you just left behind.",
   ]));
   set_exits(([
   "east" : FORESTDIR+"road31",
   "southwest" : FORESTDIR+"road33",
   "west" : MEADOWS+"meadow1",
   ]));
}
void reset(){
   ::reset();
    if(!present("sign"))
      new("/d/common/obj/areas/meadow_sign.c")->move(TO);
}
