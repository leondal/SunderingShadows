#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on one of the roads built on the tree branches of the elven "
   "city of Aketon. A house with several glass windows is built on the "
      "branch off to the west. The road mark besides you reads: Aketon "
      "Crossroad bar to the west.");
   set_smell("default","You smell alcohols from citizens passed you.");
   set_listen("default","You hear sounds of a bar coming from west.");
   set_exits( (["east":RPATH1+"1one38",
      "west":RPATH1+"1one36"]) );
}
