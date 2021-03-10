//changed by Circe 11/1/04 to use inherit
#include "/d/dagger/aketon/short.h"

inherit TREEOUT;

void create() {
   ::create();
   set_short("A room of Aketon");
   set_long("%^GREEN%^A room of Aketon%^RESET%^
Nothing now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["east":RPATH5+"5three5",
      "southwest":RPATH5+"5three1"]) );
}
