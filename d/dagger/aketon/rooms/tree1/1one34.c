#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the huge tree branches of the elven "
      "city of Aketon. There is a large structure to the east of road. "
      "It looks like some sort of government bureau. The road mark "
      "besides you reads: Aketon Revenue to the east.");
   set_exits( (["east":RPATH1+"1one35",
      "west":RPATH1+"1one1"]) );
}
