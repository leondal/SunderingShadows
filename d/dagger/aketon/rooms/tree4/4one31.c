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
   set_exits( (["north":RPATH4+"4one26",
      "southeast":RPATH4+"4one40",
      "south":RPATH4+"4one39",
      "southwest":RPATH4+"4one37"]) );
}
