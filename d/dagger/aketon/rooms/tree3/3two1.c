#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^\n"+
   "You are on a wide platform formed by the branching of the tree you"+
   " are stepping on. There are broad ways on the branches of the tree"+
   " leading into many different directions from here. The area appears"+
   " to be mostly made up of houses. There is a door to the southwest"+
   " that leads into a rather large looking house with a tall roof."+
   " To the northwest is a cherry wood door. Steps continue leading up"+
   " and down the tree.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city in the distance.");
   set_door("cherry door",RPATH3+"3two6","northwest",0);
   set_door("door",RPATH3+"3two13","southwest","aketon key");
   set_locked("door",1);
   set_exits( (["up":RPATH3+"3three1",
      "down":RPATH3+"3one1",
      "north":RPATH3+"3two7",
      "east":RPATH3+"3two10",
      "southeast":RPATH3+"3two15",
      "south":RPATH3+"3two14",
      "southwest":RPATH3+"3two13",
      "northwest":RPATH3+"3two6"]) );
}
