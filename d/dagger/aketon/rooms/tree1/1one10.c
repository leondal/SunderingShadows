#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. A house decorated with a lot of gold is to the "
      "north of here. Many people entering that house and many coming "
      "out with some jewels or gems with them. The road mark besides you "
      "reads: Aketon Jewellery to the north");
   set_exits( (["north":RPATH1+"1one4",
      "south":RPATH1+"1one18"]) );
}
