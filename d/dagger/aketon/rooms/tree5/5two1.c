//changed by Circe 11/1/04 to use inherit
#include "/d/dagger/aketon/short.h"

inherit TREEOUT;

void create() {
   ::create();
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^
You are on a wide platform formed by the branching of the tree you are "+
   "stepping on. There are broad ways on the branches of the tree leading into "+
   "all different directions from here. Steps continue leading up and down the tree.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["up":RPATH5+"5three1",
      "down":RPATH5+"5one1",
      "north":RPATH5+"5two8",
      "northeast":RPATH5+"5two9",
      "southeast":RPATH5+"5two15",
      "south":RPATH5+"5two14",
      "southwest":RPATH5+"5two13",
      "northwest":RPATH5+"5two7"]) );
}
