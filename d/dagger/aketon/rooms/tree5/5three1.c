//changed by Circe 11/1/04 to use inherit
#include "/d/dagger/aketon/short.h"

inherit TREEOUT;

void create() {
   ::create();
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^
You are on a wide platform formed by the branching of the tree you are "+
   "stepping on. There are broad ways on the branches of the tree leading into "+
   "all different directions from here. Steps continue further up the tree but "+
   "you can tell that you are almost to the top. This level is much smaller than "+
   " the last.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["up":RPATH5+"5top",
      "down":RPATH5+"5two1",
      "northeast":RPATH5+"5three4",
      "south":RPATH5+"5three6",
      "northwest":RPATH5+"5three3"]) );
}
