#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^\n"+
   "You are on the stairs on the third level of the residential tree"+
   " of Aketon. This entire section seems to be devoted to a garden,"+
   " however, for the enjoyment of the elven citizens. Wide platforms"+
   " lead out into many different directions from here. The steps"+
   " around the giant trunk lead up higher or back down to the lower"+
   " levels.");
   set_smell("default","The smells of the forest and garden surround"+
   " you.");
   set_listen("default","The wind rustles gently through the leaves.");
   set_exits( (["up":RPATH3+"3top",
      "down":RPATH3+"3two1",
      "northeast":RPATH3+"3three3",
      "south":RPATH3+"3three6",
      "southwest":RPATH3+"3three5",
      "northwest":RPATH3+"3three2"]) );
}
