#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^
You are on a wide platform formed by the branching of the tree you are "+
   "stepping on. There are broad ways on the branches of the tree leading into "+
   "all different directions from here. The area appears to be mostly made"+
   " up of houses. Steps continue leading up and down the tree.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["up":RPATH3+"3two1",
      "down":RPATH3+"3step3",
      "north":RPATH3+"3one18",
      "east":RPATH3+"3one24",
      "southeast":RPATH3+"3one31",
      "southwest":RPATH3+"3one30",
      "northwest":RPATH3+"3one17"]) );
}
