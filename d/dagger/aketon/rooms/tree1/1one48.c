#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the huge tree branches of the elven "
      "city of Aketon. To the south you see a large shop. The road mark "
      "besides you reads: Aketon Archery to the south.");
   set_exits( (["north":RPATH1+"1one40",
      "south":RPATH1+"1one56"]) );
}
