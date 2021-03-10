#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the huge tree branches of the elven "
      "city of Aketon. To the north you see a large building. The road "
      "mark besides you reads: Aketon church to the north.");
   set_exits( (["north":RPATH1+"1one20",
      "south":RPATH1+"1one1"]) );
}
