#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. Lots of people passes you heading the house to the "
      "north. The road mark besides you reads: Aketon Alchemy to the "
      "north.");
   set_exits( (["north":RPATH1+"1one12",
      "south":RPATH1+"1one29"]) );
}
