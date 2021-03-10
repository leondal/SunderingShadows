#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. A which looks like a resturant is to the east. "
      "The road mark besides you reads: Aketon Sparrow Inn to the east.");
   set_smell("default","Smells of food triggered your hunger.");
   set_exits( (["east":RPATH1+"1one31",
      "west":RPATH1+"1one29"]) );
}
