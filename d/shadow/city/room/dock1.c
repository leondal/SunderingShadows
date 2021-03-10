//Octothorpe (12/15/16)
//Shadow, Dock 1

#include <std.h>
#include "../defs.h"
inherit INH+"dock";

void create()
{
   ::create();
   set_exits(([
      "north" : ROOMS"dolanco2",
      "south" : "/d/shadow/virtual/sea/shadow.dock",
   ]));
   set_long(::query_long()+" Looking down into the water, you see roof of a sunken %^BOLD%^%^BLACK%^black tower%^RESET%^ peering just above the sea level.");
   add_item(({"tower","black tower"}),"Remnants of ancient bastion submerged under the water can be seen here. This tower has a trapdoor ontop of it. People walking by the dock turn their eyes, either on intent not to be seen seeing it or by compulsion of magic. You think if you brave enough you could <swim to tower> from this spot...");
}

void init()
{
    ::init();
    add_action("swim_to","swim");
}

int swim_to(string str)
{
    tell_room(TO,"%^BLUE%^"+TP->QCN+" quickly descends into water and swims away.",TP);
    write("%^BLUE%^You quickly descend into water and make your way to the tower.");
    TP->move(ROOMS+"/assassinoutside");
    TP->force_me("look");
    return 1;
}
