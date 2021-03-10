#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Wyndaloth Lane");
   set_long("%^GREEN%^Wyndaloth Lane%^RESET%^
Nothing now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["north":RPATH4+"4one13",
      "northeast":RPATH4+"4one14",
      "east":RPATH4+"4one18",
      "southwest":RPATH4+"4one45"]) );
}
