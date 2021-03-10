#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the huge tree branches of the elven "
      "city of Aketon. A large building is constructed down the southern "
      "branching. The outlook gives you an impression that it must be "
      "some important structure. The road sign besides you reads: Banks "
      "of Shadow Aketon Branch to the south.");
   set_exits( (["north":RPATH1+"1one1",
      "south":RPATH1+"1one47"]) );
}
