#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. To the east you see a shop with a large double "
      "door. Many adventurers coming out of the shop looks shiny and "
      "smiles happily at you. The road mark besides you reads: Aketon "
      "Armoury to the east.");
   set_exits( (["east":RPATH1+"1one51",
      "west":RPATH1+"1one49"]) );
}
