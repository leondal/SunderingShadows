#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Balcony overlooking the forest");
   set_long("%^GREEN%^Balcony overlooking the forest%^RESET%^
Nothing now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["southwest":RPATH4+"4one14"]) );
}
