#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the tree branches of the elven "
   "city of Aketon. An ornate structure towers to the south. It must "
      "be a place of importance. The road mark besides you reads: Aketon "
      "Whitedoll Hotel to the south.");
   set_exits( (["north":RPATH1+"1one38",
      "south":RPATH1+"1one55"]) );
}
