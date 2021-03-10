#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the tree branches of the elven "
      "city of Aketon. The house to the west is quite old and looks "
      "not attractive like the houses in the reset of the city. People "
      "come out of that house and walk passed you. You notice that their "
      "clothes are new. The road mark besides you reads: Aketon Garment "
      "Outlet to the west.");
   set_exits( (["east":RPATH1+"1one45",
      "west":RPATH1+"1one43"]) );
}
