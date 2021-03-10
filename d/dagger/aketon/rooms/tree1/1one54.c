#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the tree branches of the elven "
      "city of Aketon. A large wooden house is at the end of the road to "
      "the south. The road mark besides you reads: Aketon General Store "
      "to the south.");
   set_exits( (["north":RPATH1+"1one45",
      "south":RPATH1+"1one62"]) );
}
