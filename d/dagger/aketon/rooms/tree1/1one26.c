#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. You see many citizens and adventurers coming in "
      "and out from the large house towards the west. The road mark "
      "besides you reads: Aketon Spell Shop to the west.");
   set_exits( (["east":RPATH1+"1one27",
      "west":RPATH1+"1one25"]) );
}
