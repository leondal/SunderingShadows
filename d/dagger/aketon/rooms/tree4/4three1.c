#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A room of Aketon");
   set_long("%^GREEN%^A room of Aketon%^RESET%^
Nothing now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["up":RPATH4+"4top",
      "down":RPATH4+"4two1",
      "north":RPATH4+"4three2",
      "east":RPATH4+"4three3",
      "southwest":RPATH4+"4three4"]) );
}
