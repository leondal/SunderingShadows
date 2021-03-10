#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. A wooden structure shaped long and stretching "
      "stalls to the east. The road mark besides you reads: Aketon "
      "stables to the east.");
   set_smell("default","Smells of horses reached you from the east.");
   set_exits( (["east":RPATH1+"1one42",
      "west":RPATH1+"1one40"]) );
}
