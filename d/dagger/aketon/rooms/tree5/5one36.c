//changed by Circe 11/1/04 to use inherit
#include "/d/dagger/aketon/short.h"

inherit TREEOUT;

void create() {
   ::create();
   set_short("Avenue of Preistoka");
   set_long("%^GREEN%^Avenue of Preistoka%^RESET%^
Nothing right now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["northeast":RPATH5+"5one31",
      "southwest":RPATH1+"1one7"]) );
}
