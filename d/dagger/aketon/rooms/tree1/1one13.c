#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. To the north you see a simple but large house. A "
      "lot of citizens passes you to and from the house. The road mark "
      "besides you reads: Wallados' House of Healing to the north.");
   set_exits( (["north":RPATH1+"1one5",
      "south":RPATH1+"1one22"]) );
}
