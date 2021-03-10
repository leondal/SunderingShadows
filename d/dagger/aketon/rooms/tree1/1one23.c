#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. A house is to the east, some dim light passes the "
      "windows reach your eyes. The road mark besides you read: Aketon "
      "Tobacco Shop to the east.");
   set_smell("default","You sell strong odors of tobaccos from the east.");
   set_exits( (["east":RPATH1+"1one24",
      "west":RPATH1+"1one22"]) );
}
