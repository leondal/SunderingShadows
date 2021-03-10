#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. A house is towards the end of the road branch. You "
      "can see the sign hanging outside the door of the house from quite "
      "a distance. The road mark besides you reads: Aketon Tailor to the "
      "south.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["north":RPATH1+"1one49",
      "south":RPATH1+"1one63"]) );
}
