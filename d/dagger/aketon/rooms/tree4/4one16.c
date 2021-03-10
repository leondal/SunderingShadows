#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Avenue of Magiciana");
   set_long("%^GREEN%^Avenue of Magiciana%^RESET%^
Nothing now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["north":RPATH4+"4one12",
      "southeast":RPATH4+"4one45",
      "southwest":RPATH4+"4one22",
      "northwest":RPATH4+"4one11"]) );
}
