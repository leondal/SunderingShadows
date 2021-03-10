#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^
You are on a wide platform formed by the branching of the tree you are "+
   "stepping on. There are broad ways on the branches of the tree leading into "+
   "all different directions from here. Steps continue leading up and down the tree.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["up":RPATH4+"4two1",
      "northeast":RPATH4+"4one17",
      "southeast":RPATH4+"4one27",
      "southwest":RPATH4+"4one26",
      "northwest":RPATH4+"4one16"]) );
}
