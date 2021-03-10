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
   set_exits( (["north":RPATH4+"4one8",
      "northeast":RPATH4+"4one9",
      "southeast":RPATH4+"4one19",
      "southwest":RPATH4+"4one17"]) );
}
