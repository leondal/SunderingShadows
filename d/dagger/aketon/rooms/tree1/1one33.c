#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the huge tree branches of the elven "
      "city of Aketon. There is a large building towards the west. The "
      "road mark besides you reads: Aketon Treasury to the west.");
   set_smell("default","You smell the strong smell of money carried by "
      "the wind from the west.");
   set_exits( (["east":RPATH1+"1one1",
      "west":RPATH1+"1one32"]) );
}
