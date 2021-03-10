#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. Several adventurers ride passes you from the north "
      "and leaves south. The road mark besides you reads: Aketon Exotic "
      "Mounts to the north.");
   set_smell("default","Smells of animals carried by the wind from the "
      "north.");
   set_exits( (["north":RPATH1+"1one11",
      "south":RPATH1+"1one27"]) );
}
